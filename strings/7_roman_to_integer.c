#include <stdio.h>
#include <string.h>

char s[10000];
const char ROMAN_CHAR[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
const int  ROMAN_VAL[] =  { 1, 5, 10, 50, 100, 500, 1000};
const int N_CHAR = 7;

int makeIntFromRoman(char s[]) {
    int n = strlen(s);
    int result = 0;
    int last_seen = 0;

    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<N_CHAR; j++) {
            if (s[i] == ROMAN_CHAR[j]) {
                if (last_seen > ROMAN_VAL[j]) {
                    result -= ROMAN_VAL[j];
                }
                else {
                    result += ROMAN_VAL[j];
                    last_seen = ROMAN_VAL[j];
                }
                break;
            }
        }
    }
    return result;
}
int main() {
    freopen("roman_to_integer.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int d = makeIntFromRoman(s);
        printf("%d\n", d);
    }
}