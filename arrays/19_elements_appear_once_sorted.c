#include <stdio.h>

int a[10000000];
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

// void area(int a[], int i, int j) {
//     // area without considering blocks inside (i, j)
//     return min(a[i], a[j])*(j-i-1);
// }
int main() {
    freopen("elements_appear_once_sorted.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        print1D(a, n);

        int i, j;
        for (i=0, j=1; i<n-1 && j<n; i+=2, j+=2) {
            if (a[i] != a[j]) {
                // printf("%d != %d", a[i], a[j]);
                break;
            }
        }

        printf("%d\n", a[i]);

        
        
    }
    return 0;
}