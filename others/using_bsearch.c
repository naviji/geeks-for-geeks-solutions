#include <stdio.h>
#include <stdlib.h>

int compfunc(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int a[4] = {1, 12, 15, 55};
    int *found;

    int key = 10;
    found = bsearch(&key, a, 4, sizeof (int), compfunc);
    if (found == NULL) {
        printf("Did not find %d in array.\n", key);
    }
    else printf("Found %d in array.\n", *found);

}