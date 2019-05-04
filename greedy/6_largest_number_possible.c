#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// not working

int compare(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int main() {
	//code
    freopen("largest_number_possible.txt", "r", stdin);
    int t, n, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        int result = 0;
        while(n--){
            if (k-9 >= 0) {
                result = result*10 + 9;
                k -= 9;
            }
            else {
                result = result*10 + k;
                k -= k;
            }
        }

        if (k>0) {
            printf("-1\n");
        }
        else {
            printf("%d\n", result);
        }
        
        
    }
	return 0;
}