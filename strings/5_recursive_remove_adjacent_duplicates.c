#include <stdio.h>
#include <string.h>


/*
Code not working. Not able to remove duplicate words.
Also the current 'implementation' is not recursive.
Input:
mississipie

Its Correct output is:
mpie
*/

char s[100];

void removeAdjacentDuplicates(char a[]) {
    int n = strlen(a);

    int i=0;
    int j=1;

    int seen_dup = 0;
    while (i<n && j<n) {
        while (i<n && j<n && a[i] != a[j]) {
            printf("%c", a[i]);
            i++;
            j++;
        }
        if (i<n && j<n) {
            // seen a duplicate char
            while (i<n && j<n && a[i]==a[j]) {
                i++;
                j++;
            }
        }
        i++;
        j++;
    }

    // if (a[n-2] != a[n-3])

    if (a[n-1] != a[n-2]) {
        printf("%c", a[n-1]);
    }
}

int main() {
    freopen("recursive_remove_adjacent_duplicates.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        removeAdjacentDuplicates(s);
        printf("\n");
    }

}