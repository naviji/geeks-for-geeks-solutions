#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 550


int a[110];
char s[110][5];



int compareInts(int a, int b) {
    return b-a;
}

int comparefunc(const void * ta, const void * tb) {
    // return strcmp((char *)ta, (char *)tb);
    char* a = (char *)ta;
    char* b = (char *)tb;

    char version1[20];
    char version2[20];

    strcpy(version1, a);
    strcat(version1, b);

    strcpy(version2, b);
    strcat(version2, a);
    // strcat(a, b);
    // strcat(b, a);
    return compareInts(atoi(version1), atoi(version2));
}

int main() {
    freopen("largest_number_formed_from_array.txt", "r", stdin);
    int n, t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%s", s[i]);
        }

        qsort(s, n, sizeof(s[0]), comparefunc);
        for (int i=0; i<n; i++) {
            printf("%s", s[i]);
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
