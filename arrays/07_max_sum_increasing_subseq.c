#include <stdio.h>

int a[1000000];
int memo[1000000];

int max(int a, int b) {
    return (a>b) ? a : b;
}
int main() {
	//code
    freopen("max_sum_increasing_subseq.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        
        int max_seen = -1;
        
        // processing
        // memo[0] = a[0];
        for (int i=0; i<n; i++) {
            memo[i] = a[i];
            for (int j=i-1; j>=0; j--) {
                if (a[j] < a[i]) {
                    memo[i] = max(memo[i], a[i]+memo[j]);
                }
            }
            if (memo[i] > max_seen) {
                max_seen = memo[i];
            }
        }
        printf("%d\n", max_seen);

        

        
    }
	return 0;
}