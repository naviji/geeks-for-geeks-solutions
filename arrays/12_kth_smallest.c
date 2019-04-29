#include <stdio.h>
#include <stdlib.h>

int a[100000];

int compareInts(const void* a, const void* b) {
    return (*(int *)a - *(int *)b);
}

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

int partition(int arr[], int left, int right) {
    // take last element as pivot
    int pivot = arr[right];
    int i = left - 1;
    
    for (int j=left; j<right; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[++i], &arr[j]);
        }
    }
    swap(&arr[++i], &arr[right]);
    return i;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi-1);
        quicksort(arr, pi+1, right);
    }
}

int findKthLargest(int arr[], int n, int k) {
    int left = 0;
    int right = n-1;
    int kth;
    while (1) {
        int idx = partition(arr, left, right);
        if (idx == k-1) {
            kth = arr[idx];
            break;
        }
        if (idx < k-1) {
            left = idx+1;
        }
        else {
            right = idx-1;
        }
    }
    return kth;
}

int main() {
    freopen("kth_smallest.txt", "r", stdin);
    int n, t, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &k);

        printf("%d\n", findKthLargest(a, n, k));

    }

    return 0;
}