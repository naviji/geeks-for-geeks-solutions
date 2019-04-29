#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[10000000];

// Can be improved using a balanced BST or a deque.
// TODO: C++ optimized implementation.


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
        for (int i=0; i<=n-k; i++) {
            int max = a[i];
            for (int j=1; j<k; j++) {
                if (a[i+j] > max)
                    max = a[i+j];
            }
            printf("%d ", max);
        }
        printf("\n");
        
        


        
    }
	return 0;
}