// Kedan's Algorithm

#include <stdio.h>
#include <limits.h>

int a[1000000];

int main() {
    freopen("kedane.txt", "r", stdin);
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        int max_found = INT_MIN;
        int curr_sum = 0;
        for (int i=0; i<n; i++) {
            curr_sum += a[i];
            if (curr_sum > max_found) {
                max_found = curr_sum;
            }
            if (curr_sum < 0) {
                curr_sum = 0;
            }
        }
        printf("%d\n", max_found);
    }
}