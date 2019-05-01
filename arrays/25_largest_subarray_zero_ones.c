#include <stdio.h>

int maxLen(int a[], int n)
{
    int ans = 0;
    for (int i=0; i<n; i++) {
        int nz = 0;
        int no = 0;
        for (int j=i; j<n; j++) {
            if (a[j] == 0) nz++;
            if (a[j] == 1) no++;
            if (no == nz) ans = (ans > (j-i+1)) ? ans : j-i+1;
        }
    }
    return ans;
}

int main() {
    int n, t;
    int a[1000];

    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        printf("%d\n", maxLen(a, n));
    }
}