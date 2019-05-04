#include <stdio.h>
#include <stdlib.h>

int arr[1000];

int compare(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int main() {
	//code
    freopen("maximize_toys.txt", "r", stdin);
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        qsort(arr, n, sizeof(int), compare);
        int nbuy = 0;
        int i=0;
        while (i<n) {
            if (k-arr[i] >= 0) {
                k -= arr[i];
                nbuy++;
            }
            else break;
            i++;
        }
        printf("%d\n", nbuy);
        
    }
	return 0;
}