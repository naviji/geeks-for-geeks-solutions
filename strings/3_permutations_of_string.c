#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int start, int end) {
    if (start == end) {
        printf("%s\n", s);
        return;
    }

    for (int i=start; i<=end; i++) {
        swap(&s[start], &s[i]);
        permute(s, start+1, end);
        swap(&s[start], &s[i]); // backtrack
    }

}

int main() {
    char s[] = "abc";
    int n = strlen(s);

    permute(s, 0, n-1);
}