#include <stdio.h>
#include <string.h>


char s[2000];
int count[256];

int main() {
    freopen("remove_duplicates.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    getchar();
    // gets()
    while (t--) {
        memset(count, 0, sizeof count);
        // scanf("%s", s);
        // gets(s);
        scanf("%[^\n]%*c", s); 
        // scanf("%s", s);
        // fgets(s, 2000, stdin);
        n = strlen(s);
        for (int i=0; i<n; i++) {
            // printf("%c",s[i]);
            if (count[s[i]] == 0) {
                printf("%c", s[i]);
                count[s[i]]++;
            }
        }
        printf("\n");

    }

}