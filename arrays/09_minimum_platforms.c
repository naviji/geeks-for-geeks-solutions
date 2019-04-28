#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// THIS CODE IS NOT ACCEPTED 
int a[1003];
int d[1003];
// int overlap[1003];

int max(int a, int b) {
    return (a>b) ? a : b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int isOverlap(int t1a, int t1d, int t2a, int t2d) {
    return ((t1d >= t2a) && (t2d >= t1a));
}

int compare(const void * a, const void * b) {
    return (*(int *)a - *(int *)b);
}
int main() {
	//code
    freopen("minimum_platforms.txt", "r", stdin);
	int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i=0; i<n; i++) {
            scanf("%d", &d[i]);
        }
        
        // processing
        qsort(a, n, sizeof(int), compare);
        qsort(d, n, sizeof(int), compare);

        // merge them and process as one array
        int i=1;
        int j=0;

        int max_platforms = 1;
        int curr_platforms = 1;

        while (i<n && j<n) {
            if (a[i] <= d[j]) {
                // next even in timeline is an arrival
                curr_platforms++;
                i++;

                if (curr_platforms > max_platforms) {
                    max_platforms = curr_platforms;
                }
            }
            else {
                // a train is leaving
                curr_platforms--;
                j++;
            }
        }

        printf("%d\n", max_platforms);


        
    }
	return 0;
}