#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*

Given an array A of positive integers of size N, where each value 
represents number of chocolates in a packet. Each packet can have 
variable number of chocolates. There are M students, the task is 
to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the 
students having packet with maximum chocolates and student having
 packet with minimum chocolates is minimum.

*/


unsigned int a[10000000];

int compfunc(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int square(int a) {
    return a*a;
}

int min(int a, int b) {
    return (a<b) ? a : b;
}

int main() {
	//code
    int n, t, s;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &s);
        qsort(a, n, sizeof(int), compfunc);
        
        int min_diff = INT_MAX;
        for (int i=0; i<=n-s; i++) {
            min_diff = min(min_diff, a[i+s-1]-a[i]);
        }
        printf("%d\n", min_diff);
        
    }
	return 0;
}
