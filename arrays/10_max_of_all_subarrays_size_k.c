#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[10000000];


int max(int a, int b) {
    return (a>b) ? a : b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int compare(const void * a, const void * b) {
    return (*(int *)a - *(int *)b);
}

int main() {
	//code
    freopen("max_of_all_subarrays_size_k.txt", "r", stdin);
	int n, t, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        
        // processing
        
        


        
    }
	return 0;
}