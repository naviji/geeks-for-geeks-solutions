#include <stdio.h>
#include <string.h>

char s[20];

int a_toi(char s[]) {
    int n = strlen(s);
    int result = 0;
    int sign = 1;
    int i=0;
    if (s[0] == '-') {
        sign = -1;
        i++;
    }
    while (i<n) {
        if (s[i]>='0' && s[i]<='9') {
            result = result*10 + (s[i]-'0');
        }
        else {
            return -1;
        }
        i++;
    }
    return result*sign;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        printf("%d\n", a_toi(s));

    }
}