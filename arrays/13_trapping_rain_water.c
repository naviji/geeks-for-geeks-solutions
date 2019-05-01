#include <stdio.h>

int a[10000000];
int l[10000000];
int r[10000000];

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

        l[0] = a[0];
        for (int i=1; i<n; i++) {
            if (a[i] > l[i-1]) {
                l[i] = a[i];
            }
            else {
                l[i] = l[i-1];
            }
        }

        r[n-1] = a[n-1];
        for (int i=n-2; i>=0; i--) {
            if (a[i] > r[i+1]) {
                r[i] = a[i];
            }
            else {
                r[i] = r[i+1];
            }
        }

        int total_water = 0;
        for (int i=1; i<n-1; i++) {
            int possible_water = min(l[i-1], r[i+1]) - a[i];
            if (possible_water > 0) {
                total_water += possible_water;
            }
        }

        printf("%d\n", total_water);
        // printf("hell");
        
    }
    return 0;
}