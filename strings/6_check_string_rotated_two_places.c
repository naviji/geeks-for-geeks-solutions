#include <stdio.h>
#include <string.h>

char str1[100];
char str2[100];

void shiftLeft(char s[]) {
    int n = strlen(s);
    char first = s[0];
    char second = s[1];
    for (int i=2; i<n; i++) {
        s[i-2] = s[i];
    }
    s[n-1] = second;
    s[n-2] = first;
}

void shiftRight(char s[]) {
    int n = strlen(s);
    char last = s[n-1];
    char secondLast = s[n-2];
    for (int i=n-1; i>=2; i--) {
        s[i] = s[i-2];
    }
    s[0] = secondLast;
    s[1] = last;
}
int main() {
    freopen("check_string_rotated_two_places.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str1);
        scanf("%s", str2);


        // shiftLeft(str2);
        shiftRight(str2);
        int same_rotate_right = strcmp(str1, str2);
        shiftLeft(str2);

        shiftLeft(str2);
        int same_rotate_left = strcmp(str1, str2);
        shiftRight(str2);
        
        if ((same_rotate_left==0) || (same_rotate_right==0)) {
            printf("1\n");
        }
        else printf("0\n");


    }
}