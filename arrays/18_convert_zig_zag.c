#include <stdio.h>

// TO DO: Not complete.

int a[10000000];
// int l[10000000];
// int r[10000000];


int min(int a, int b) {
    return (a<b) ? a : b;
}


int main() {
    freopen("trapping_rain_water.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        
        
        
    }
    return 0;
}