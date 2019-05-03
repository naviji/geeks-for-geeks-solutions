#include <stdio.h>
#include <string.h>

char s[1000];
char a[1000][1000];

void printLongestCommonPrefix(char a[][1000], int n, int s) {
    int flag=1;
    for (int i=0; i<s; i++) {
        char c = a[0][i];
        for (int j=1; j<n; j++) {
            if (a[j][i] != c) {
                if (flag) {
                    printf("-1");
                }
                return;
            }
        }
        printf("%c", c);
        flag = 0;
    }
}

int min(int a, int b) {
    return (a<b) ? a : b;
}

int main() {
    freopen("longest_common_prefix.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        int shortestLen = 1000000;
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", a[i]);
            shortestLen = min(shortestLen, strlen(a[i]));
        }

        printLongestCommonPrefix(a, n, shortestLen);
        printf("\n");

    }
}