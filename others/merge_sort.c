#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_sort(int arr[], int temp[], int left, int right);
void merge(int arr[], int temp[], int left, int mid, int right);

void print1D(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2 , 1, 3, 4, 3, 5, 6, 7};
    int n = sizeof arr/sizeof arr[0];
    int temp[n];

    memset(temp, 0, sizeof temp);
    print1D(arr, n);
    merge_sort(arr, temp, 0, n);
    print1D(arr, n);
}


void merge_sort(int a[], int temp[], int l, int r) {
    if (l < r) {
        int mid = l + (r-l)/2;
        merge_sort(a, temp, l, mid);
        merge_sort(a, temp, mid+1, r);
        merge(a, temp, l, mid, r);
    }
}

void merge(int a[], int temp[], int l, int m, int r) {

    int i=l;
    int j=m;
    int k=l;
    while (i<m && j<r) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while (i<m) {
        temp[k++] = a[i++];
    }
    while (j<r) {
        temp[k++] = a[j++];
    }

    // copy back
    for (int i=l; i<r; i++) {
        a[i] = temp[i];
    }
}