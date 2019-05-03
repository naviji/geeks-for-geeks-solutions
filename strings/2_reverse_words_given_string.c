#include <stdio.h>
#include <string.h>

char s[2000];
char a[2000][2000];

int joinStrings(char a[2000][2000], char s[]) {
  int i=0, j=0, k=0;
  int len = strlen(s);
  while (j<len && s[j] != '\0') {
    i = 0;
    while (j<len && s[j] != '.') {
      a[k][i] = s[j];
      i++;
      j++;
    }
    a[k][i] = '\0';
    k++;
    j++;
  }
  return k;
}

int main() {
  freopen("reverse_words.txt", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = joinStrings(a, s);
    for (int i=n-1; i>=0; i--) {
      if (i==0) printf("%s\n", a[i]);
      else
        printf("%s.", a[i]);
    }

  }
}
