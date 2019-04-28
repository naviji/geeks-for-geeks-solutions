#include <stdio.h>

// int a[10000000];

int main() {
	//code
    freopen("missing_number.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int sum = 0;
        int x;
        for (int i=0; i<n-1; i++) {
            scanf("%d", &x);
            sum += x;
        }
        int total = ((n*(n+1))/ 2);
        printf("%d\n", total-sum);

        
    }
	return 0;
}