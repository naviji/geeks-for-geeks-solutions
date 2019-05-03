#include <stdio.h>
#include <string.h>

// Not completed.
// Need to use Knuth-MOrris-Pratt prefix suffix matching
// algorithm. 

char s[100];
char temp[100];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);

        for (int i=0; i<n; i++) {
            temp[i] = s[i];
        }
        int j = 0;
        for (int i=n-1; i>=0; i--) {
            temp[n+j] = s[i];
            j++;
        }
        temp[2*n] = '\0';

        int i=0;
        int j=2*n-1;
        while (i<j) {
            if (temp[i] == temp[j]) {
                i++;
                j--;
            }
        }

        printf("%s\n", temp);
    }
}