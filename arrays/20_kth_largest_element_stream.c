#include <stdio.h>
#include <stdlib.h>
// #include <iostream>



// TO DO: IMPLEMENT C VERSION
// priority queue?
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