#include <stdio.h>
#include <string.h>

int strstr_my(char s[], char x[])
{
    int xs = strlen(x);
    int ss = strlen(s);
    
    int i=0;
    int j=0;
    
    while (i<ss && j<xs) {
        int t = i;
        while (t<ss && j<xs && s[t]==x[j]) {
            t++;
            j++;
        }
        if (j==xs) {
            return i;
        }
        i++;
        j=0;
        
    }
    return -1;
}

int main() {
    char s[] = "twoyearsleft.";
    char x[] = "left";
    printf("%d\n", strstr_my(s, x));
}