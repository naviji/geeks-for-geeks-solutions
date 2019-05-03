#include <stdio.h>
#include <string.h>

int memo[110][110];
char str1[110];
char str2[110];

int main() {
    freopen("longest_common_substring.txt", "r", stdin);
    int t, m, n;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &m, &n);
        memset(memo, 0, sizeof memo);

        scanf("%s", str1);
        scanf("%s", str2);

        int max_yet = 0;

        // leave the initial row and column
        // of memo full of zeroes to make code
        // simpler.
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (str1[j] == str2[i]) {
                    memo[i+1][j+1] = 1 + memo[i][j];
                    if(memo[i+1][j+1] > max_yet) {
                        max_yet = memo[i+1][j+1];
                    }
                }
            }
        }
        
        printf("%d\n", max_yet);



    }
}