#include <stdio.h>
#include <stdlib.h>

int a[1000000];
int smallest[1000000];
int greatest[1000000];

// TO DO: Not complete.

int compfunc(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int square(int a) {
    return a*a;
}

int printArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
	//code
    freopen("left_side_smaller_right_greater.txt", "r", stdin);
    int n, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        // fill smallest;
        int smallest_yet = a[n-1];
        smallest[n-1] = a[n-1];

        for (int i=n-2; i>=0; i--) {
            if (a[i] < smallest_yet) {
                smallest[i] = a[i];
                smallest_yet = a[i];
            }
            else {
                smallest[i] = smallest_yet;
            }
        }

        // fill smallest;
        int greatest_yet = a[0];
        greatest[0] = a[0];

        for (int i=1; i<n; i++) {
            if (a[i] > greatest_yet) {
                greatest[i] = a[i];
                greatest_yet = a[i];
            }
            else {
                greatest[i] = greatest_yet;
            }
        }
        

        int found = 0;
        for (int i=1; i<n-1; i++) {
            if ((a[i]>=greatest[i-1]) && (a[i]<=smallest[i+1])) {
                printf("%d\n", a[i]);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("%d\n", -1);
        }


    }
	return 0;
}
