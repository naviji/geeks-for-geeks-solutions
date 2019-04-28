#include <stdio.h>

#define MAX_LEN 10000000
unsigned int a[MAX_LEN];

void printSubIndex(int a[], int n, int sum) {
    unsigned int curr_sum;
    for (int i=0; i<n; i++) {
        curr_sum = 0;
        for (int j=i; j<n; j++) {
            curr_sum += a[j];
            if (curr_sum == sum) {
                printf("%d %d\n", i+1, j+1);
                return;
            }
            else if (curr_sum > sum) break;
        }
    }
    printf("-1\n");
}

int main() {
    freopen("subarray_given_sum.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    unsigned int n, sum;
    while (t--) {
        scanf("%d %d", &n, &sum);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        printSubIndex(a, n, sum);
    }
}
