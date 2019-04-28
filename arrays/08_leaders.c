#include <stdio.h>

int a[10000000];
int leaders[10000000];

int max(int a, int b) {
    return (a>b) ? a : b;
}
int main() {
	//code
    freopen("leaders.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        
        // processing
        int leader_count = 0;

        leaders[0] = a[n-1];
        leader_count++;

        for (int i=n-2; i>=0; i--) {
            if (a[i] >= leaders[leader_count-1]) {
                leaders[leader_count++] = a[i]; 
            }
        }

        for (int i=leader_count-1; i>=0; i--) {
            printf("%d ", leaders[i]);
        }
        printf("\n");
        
        

        
    }
	return 0;
}