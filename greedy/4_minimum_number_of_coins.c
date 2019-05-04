#include <stdio.h>
#include <stdlib.h>

// int arr[1000];

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int main() {
	//code
    freopen("minimum_number_of_coins.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        // printf("%d\n", n);
        int ncoins = 0;
        int nval = sizeof coins/ sizeof(int);
        while (n>0) {
            for (int i=nval-1; i>=0; i--) {
                if (n >= coins[i]) {
                    printf("%d ", coins[i]);
                    n -= coins[i];
                    ncoins++;
                    break;
                }
            }
        }
        printf("\n");
        
    }
	return 0;
}