#include <stdio.h>
#include <string.h>

unsigned int count[30];

int main() {
    freopen("anagram.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    char c;
    getchar(); // to remove trailing newline in t
    while (t--) {
        memset(count, 0, sizeof count);
        while ((c=getchar()) != ' ') {
            count[c-'a']++;
        }

        while ((c=getchar()) != '\n' && c != EOF) {
            count[c-'a']--;
        }

        int flag = 1;
        for (int i=0; i<30; i++) {
            if (count[i] != 0) {
                printf("NO\n");
                flag = 0;
                break;
            }
        }

        if (flag) printf("YES\n");
    }

}

