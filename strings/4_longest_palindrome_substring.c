#include <stdio.h>
#include <string.h>

char s[10000];
int memo[10000][10000];

void printSubString(char s[], int start, int end) {
    for (int i=start; i<=end; i++) {
        printf("%c", s[i]);
    }
}

void printLongestPalindrome(char s[], int n) {
    memset(memo, 0, sizeof(memo));
    int max_len = 1;
    int start = 0;

    // mark all single letters as palindrome
    for (int i=0; i<n; i++) {
        memo[i][i] = 1;
    }

    // check if two letters substrings are palindromes.
    for (int i=0; i<n-1; i++) {
        if (s[i]==s[i+1]) {
            memo[i][i+1] = 1;
            if (max_len < 2) {
                max_len = 2;
                start = i;
            }
        }
    }


    // check if substrings of length 3 to n are palindromes.
    for (int k=3; k<=n; k++) {
        for (int i=0; i<n-k+1; i++) {
            int j = i+k-1;
            if (memo[i+1][j-1] && (s[i]==s[j])) {
                memo[i][j] = 1;
                if (max_len < k) {
                    max_len = k;
                    start = i;
                }
            }
        }
    }

    printSubString(s, start, start+max_len-1);

}

int main() {
    freopen("longest_palindrome_substring.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        // memset(s, 0, sizeof(s));
        scanf("%s", s);
        printLongestPalindrome(s, strlen(s));
        printf("\n");
    }
}