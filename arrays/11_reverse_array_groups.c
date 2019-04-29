#include <stdio.h>

int a[10000000];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int reverse(int arr[], int start, int end) {
    for (int i=0; i<(end-start)/2; i++) {
        swap(&arr[start+i], &arr[end-i-1]);
    }
}

int printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    freopen("reverse_array_groups.txt", "r", stdin);
    int n, t, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        int i;
        for (i=0; i<=n-k; i+=k) {
            reverse(a, i, i+k);
        }

        // i > n-k but there may be less than k items
        // remaining that are not reversed.
        reverse(a, i, n);

        printArr(a, n);

    }

    return 0;
}