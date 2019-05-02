#include <stdio.h>
#include <stdlib.h>

int a[10000000];

// TO DO: Not complete.

int compfunc(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int square(int a) {
    return a*a;
}

int printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	//code
    freopen("stock_buy_and_sell.txt", "r", stdin);
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        // printArr(a, n);
        
        int profit_flag = 0;

        int buy = a[0];
        int buy_index = 0;
        for (int i=1; i<n; i++) {
            // int possible_profit = a[i-1]-buy;
            // int possible_loss = a[i] 
            int possible_profit = a[i-1]-buy;
            int possible_loss = a[i]-buy;
            if (possible_profit>possible_loss) {
                if (buy_index!=i-1) {
                    printf("(%d %d) ",buy_index, i-1);
                    profit_flag = 1;
                }
                buy = a[i];
                buy_index = i;
            }
        }
        if (buy < a[n-1] && (buy_index!= n-1)) {
            printf("(%d %d) ", buy_index, n-1);
            profit_flag = 1;
        }
        if (!profit_flag) printf("No Profit");
        printf("\n");
    }
	return 0;
}
