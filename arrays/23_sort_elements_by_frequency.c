#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int val;
    int count;
} ctype;

ctype a[200];

int compfunc(const void*  a, const void* b) {
    // sort by count descending ; if equal sort by val ascending.
    int first_compare = ((ctype *)b)->count - ((ctype *)a)->count;
    return (first_compare == 0) ? ((ctype *)a)->val - ((ctype *)b)->val : first_compare;
}

int main() {
    freopen("sort_elements_by_frequency.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int x;
        int c[200];
        memset(c, 0, sizeof c);

        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            c[x]++;
            ctype newVal;
            newVal.val = x;
            newVal.count = 0;
            a[i] = newVal;
        }

        for (int i=0; i<n; i++) {
            a[i].count = c[a[i].val];
        }



        qsort(a, n, sizeof(a[0]), compfunc);

        for (int i=0; i<n; i++) {
            printf("%d ", a[i].val);
        }

        printf("\n");

        

        
        
    }
    return 0;
}   



void print1D(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


void print2D(int a[20][20], int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}
