#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int p, int n) {
    // take first element as pivot
    int i=p;
    int j=p+1;
    int x = arr[p];

    while (i<n && j<n) {
        if (arr[j] >= x) {
            j++;
        }
        else {
            swap(&arr[++i], &arr[j++]);
        }
    }
    swap(&arr[i], &arr[p]);
    return i;
}

void quicksort(int arr[], int l, int r) {
    if (l < r) {
        int m = partition(arr, l, r);
        quicksort(arr, l, m);
        quicksort(arr, m+1, r);
    }
    
}

int main() {
    int arr[] = {8, 3, 2, 1, 4, 6, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    quicksort(arr, 0, n);
    printArr(arr, n);

}