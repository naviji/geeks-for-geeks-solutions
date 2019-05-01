#include <stdio.h>
#include <stdlib.h>

int a[1000000];

int compfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
	//code
    freopen("sort_array_zero_ones.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        // Rather than sorting, we can also
        // count numbers of ones and zeros
        // and then print the zeros and ones.
        
        qsort(a, n, sizeof(int), compfunc);
        for (int i=0; i<n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");

        
    }
	return 0;
}