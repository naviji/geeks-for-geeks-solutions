#include <stdio.h>
#include <stdlib.h>

int a[10000000];

int compfunc(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int square(int a) {
    return a*a;
}

int main() {
	//code
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), compfunc);
        
        int found = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                for (int k=j+1; k<n; k++) {
                    if (square(a[i]) + square(a[j]) == square(a[k])) {
                        printf("Yes\n");
                        found = 1;
                        break;
                    }
                    if (square(a[i]) + square(a[j]) < square(a[k])) {
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (!found) {
            printf("No\n");
        }
        
    }
	return 0;
}
