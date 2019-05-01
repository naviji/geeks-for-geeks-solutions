#include <stdio.h>
#include <stdlib.h>

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

int compfunc(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}
// void area(int a[], int i, int j) {
//     // area without considering blocks inside (i, j)
//     return min(a[i], a[j])*(j-i-1);
// }
int main() {
    freopen("kth_largest_element_stream.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int k, n;
        scanf("%d %d", &k, &n);

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        
        // needs priority queue ?
        // kth smallest = -1;   

        for (int i=0; i<n; i++) {
            if (i < k-1) {
                printf("%d ", -1);
            }
            else {
                printf("%d ", a[i-k+1]);
            }
        }
        printf("\n");

        
        
    }
    return 0;
}