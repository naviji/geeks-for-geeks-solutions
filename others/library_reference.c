#include <stdio.h>
#include <assert.h>

// for all is_() and to_() commands
#include <ctype.h>

#include <stdlib.h>
// stdlib also has bsearch for binary search

#include <string.h>

int compareStrings(const void* s1, const void* s2) {
    return strcmp((char*)s1, (char*)s2);
}

void printStrings(char arr[][20], int n) {
    for (int i=0; i<n; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    int ab = 10;
    int b = 3;

    // using assert.h
    // assert (expression);
    assert (ab == b + 7);


    // using ctype.h
    assert (isalnum('A'));
    assert (isalpha('A'));
    assert (isblank(' '));
    assert (isdigit('7'));
    assert (islower('a'));
    assert (ispunct(';'));
    assert (isspace(' '));
    assert (isupper('A'));
    printf("%c\n", tolower('A'));
    printf("%c\n", toupper('b'));


    // using stdio.h
    FILE *f1 = fopen("hello_world.txt", "w");
    char s[20] = "abcdefg";
    // printf("Enter any string: ");
    // scanf("%s", s);

    fputs(s, f1);
    fclose(f1);

    // using stdlib.h

    int* a = (int*)malloc(sizeof(int)*3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    for (int i=0; i<3; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);

    // using string.h

    if (strcmp("naveen", "naveen") == 0) {
        puts("strings are same\n");
    }

    // two dimensional array of strings.
    char arr[3][20] = {"zoop", "blah", "aap"};

    for (int i=0; i<3; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    qsort(arr, 3, sizeof(char)*20, compareStrings);


    for (int i=0; i<3; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");


    strcpy(arr[0], "zanza");
    printStrings(arr, 3);
    // others include strcmp(), strcat(), strlen(), memset






}