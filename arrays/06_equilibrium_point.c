#include <stdio.h>

int a[1000000];

int main() {
	//code
    freopen("equilibrium_point.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        
        if (n == 1) {
            printf("%d\n", n);
            continue;
        }
        
        // processing
        
        int i=0;
        int j=n-1;
        
        int suml = a[i];
        int sumr = a[j];
        while (i < j) {
            if (suml >= sumr) {
                sumr += a[--j];
            }
            else {
                suml += a[++i];
            }
        }
        
        if (suml == sumr) {
            printf("%d\n", i+1);
        }
        else {
            printf("%d\n", -1);
        }

        
    }
	return 0;
}