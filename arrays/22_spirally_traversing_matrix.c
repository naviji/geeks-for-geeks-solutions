#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int a[20][20];

// int l[10000000];
// int r[10000000];

void makeIncrementalMatrix(int a[][20], int m, int n) {
    int count = 1;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            a[i][j] = count++;
        }
    }
}

int min(int a, int b) {
    return (a<b) ? a : b;
}


void print1D(int a[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int compfunc(const void * a, const void * b) {
    return *(int *)a - *(int *)b;
}


void printSpiral(int a[20][20], int m, int n) {
    int rowStart = 0;
    int rowEnd = m-1;
    int colStart = 0;
    int colEnd = n-1;

    while (rowStart<=rowEnd && colStart<=colEnd) {
        for (int i=colStart; i<=colEnd; i++) {
            printf("%d ", a[rowStart][i]);
        }
        
        rowStart++;
        for (int i=rowStart; i<=rowEnd; i++) {
            printf("%d ", a[i][colEnd]);
        }
        colEnd--;
        

        // whenever you manipulate a variable
        // check if it is in bound when using it again.
        if (rowStart <= rowEnd) {
            for (int i=colEnd; i>=colStart; i--) {
                printf("%d ", a[rowEnd][i]);
            }
            rowEnd--;
        }
        
        if (colStart <= colEnd) {
            for (int i=rowEnd; i>=rowStart; i--) {
            printf("%d ", a[i][colStart]);
            }
            colStart++;
        }
        
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

int main() {
    freopen("spirally_traversing.txt", "r", stdin);
    int t;
    scanf("%d", &t);

    while (t--) {
        int m, n;
        scanf("%d %d", &m, &n);

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d", &a[i][j]);
            }
        }

        // makeIncrementalMatrix(a, m, n);
        print2D(a, m, n);

        printSpiral(a, m, n);


        
        
    }
    return 0;
}   