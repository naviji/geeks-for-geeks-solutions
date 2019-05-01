#include <stdio.h>


void makeIncrementalMatrix(int a[][100], int m, int n) {
    int count = 1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            a[i][j] = count++;
        }
    }
}

void print2D(int a[][100], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[100][100];

    int m=, n=1;

    makeIncrementalMatrix(a, m, n);
    print2D(a, m, n);

    // for (int k=0; k<m; k++) {
    //     int i=k;
    //     int j=0;
    //     while (j<=k && j<n) {
    //         printf("%d ", a[i][j]);
    //         i--;
    //         j++;
    //     }
    //     printf("\n");
    // }

    for (int k=0; k<m; k++) {
        int i=k;
        int j=0;
        while (i >= 0) {
            printf("%d ", a[i][j]);
            i--;
            j++;
        }
        printf("\n");
    }

    // for (int k=1; k<n; k++) {
    //     int i=m-1;
    //     int j=k;
    //     while (i>=0 && j<=n-1) {
    //         printf("%d ", a[i][j]);
    //         i--;
    //         j++;
    //     }
    //     printf("\n");
    // }

    for (int k=1; k<n; k++) {
        int i=m-1;
        int j=k;
        while (j<=n-1) {
            printf("%d ", a[i][j]);
            i--;
            j++;
        }
        printf("\n");
    }
}