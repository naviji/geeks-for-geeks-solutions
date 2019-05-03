#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int memo[MAX_LEN][MAX_LEN];


void print2D(int a[MAX_LEN][MAX_LEN], int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%2d ", a[i][j]);
        }
        printf("\n");
    }
}


int max(int a, int b) {
    return (a>b) ? a : b;
}

int min(int a, int b, int c) {
    return (a<b) ? (a < c) ? a : c : (b < c) ? b : c;
}


int edit_distance(char a[], char b[], int m, int n) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }

    if (memo[m][n] != -1) {
        return memo[m][n];
    }

    if (a[m-1] == b[n-1]) {
        memo[m][n] =  edit_distance(a, b, m-1, n-1);
    }
    else {
        memo[m][n] =  1 + min(edit_distance(a, b, m-1, n),
                              edit_distance(a, b, m, n-1),
                              edit_distance(a, b, m-1, n-1));
    }
    return memo[m][n];
}

int edit_distance_iter(char a[], char b[], int m, int n) {
    int dp[MAX_LEN][MAX_LEN];
    // print2D(dp, max(m, n));
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }

        }
    }
    // print2D(dp, max(m, n));
    return dp[m][n];
}

int main() {
    char a[] = "iyrgiushdiugahfhahfkhdkdsfnksdnlgidsfsd";
    char b[] = "clxkjvosdhgowjohgdsnkfjhoqpjrpqjprojqpwojr";

    int len_a = strlen(a);
    int len_b = strlen(b);
    
    memset(memo, -1, sizeof memo);

    int distance = edit_distance_iter(a, b, len_a, len_b);
    printf("%d\n", distance);
}