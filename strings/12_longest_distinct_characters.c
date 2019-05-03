#include <stdio.h>
#include <string.h>

char str[10000];
int count[256];

int max(int a, int b) {
    return (a>b) ? a : b;
}
int main() {
    freopen("longest_distinct_characters.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    // getchar();
    while (t--) {
        scanf("%s", str);
        memset(count, 0, sizeof count);
        n = strlen(str);

        int distinct = 0;
        int max_distinct = 0;

        for (int i=0; i<n; i++) {
            if (count[str[i]] == 0) {
                // character is distinct.
                distinct++;
                count[str[i]]++;
            }
            else {
                memset(count, 0, sizeof count);
                count[str[i]] = 1;
                max_distinct = max(distinct, max_distinct);
                distinct = 1;
            }
        }
        printf("%d\n", max_distinct);

    }
}