#include <stdio.h>

// TO DO: Not complete.

int a[10000000];
// int l[10000000];
// int r[10000000];


int min(int a, int b) {
    return (a<b) ? a : b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    freopen("convert_zig_zag.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        // int flag=0;
        for (int i=0; i<n-1; i++) {
            if (!(i%2)) {
                // even index must be less
                if (a[i] > a[i+1]) {
                    swap(&a[i], &a[i+1]);
                }
            }
            else {
                if (a[i] < a[i+1])
                    swap(&a[i], &a[i+1]);
            }

        }

        for (int i=0; i<n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
        
        
    }
    return 0;
}