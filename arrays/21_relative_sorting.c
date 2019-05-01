#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[1000000];
int b[1000000];
int flag[1000000];
int count[1000000];
// int l[10000000];
// int r[10000000];

int min(int a, int b) {
    return (a<b) ? a : b;
}


void print1D(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int compfunc(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}
// void area(int a[], int i, int j) {
//     // area without considering blocks inside (i, j)
//     return min(a[i], a[j])*(j-i-1);
// }
int main() {
    freopen("relative_sorting.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);

        memset(count, 0, sizeof count);
        memset(flag, 0, sizeof flag);

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            count[a[i]]++;
        }
        
        for (int i=0; i<m; i++) {
            scanf("%d", &b[i]);
        }


        qsort(a, n, sizeof(n), compfunc);

        for (int i=0; i<m; i++) {
            while (count[b[i]] > 0) {
                printf("%d ", b[i]);
                count[b[i]]--;
                flag[b[i]] = 1;
            }
        }
        for (int i=0; i<n; i++) {
            if (!flag[a[i]]) {
                while (count[a[i]] > 0) {
                    printf("%d ", a[i]);
                    count[a[i]]--;
                }
                flag[a[i]] = 1;
            }
        }
        printf("\n");
        
        
        
    }
    return 0;
}   