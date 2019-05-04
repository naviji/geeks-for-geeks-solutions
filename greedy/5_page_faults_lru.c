#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[1000];
int pages[100];
int recent[100];

int max_recent = 0;

int compare(const void* a, const void* b) {
    return *(int *)a - *(int *)b;
}

int findPage(int x, int c) {
    for (int i=0; i<c; i++) {
        if (pages[i] == x) {
            return i;
        }
    }
    return -1;
}

int checkEmpty(int c) {
    for (int i=0; i<c; i++) {
        if (pages[i] == -1) {
            return i;
        }
    }
    return -1;
}

int findLRPage(int c) {
    int min = recent[0];
    int min_idx = 0;
    for (int i=1; i<c; i++) {
        if (recent[i] < min) {
            min = recent[i];
            min_idx = i;
        }
    }
    return min_idx;
}

int main() {
	//code
    freopen("page_faults_lru.txt", "r", stdin);
    int t, n, capacity;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &capacity);

        memset(pages, -1, sizeof pages);
        memset(recent, 0, sizeof recent);

        int idx = -1;
        int pgf = 0;
        for (int i=0; i<n; i++) {
            if ((idx = findPage(arr[i], capacity)) != -1) {
                recent[idx] = max_recent+1;
                max_recent++;
            }
            else {
                // not in pages
                pgf++;
                if ((idx = checkEmpty(capacity)) != -1) {
                    // there are empty pages.
                    pages[idx] = arr[i];
                    recent[idx] = max_recent+1;
                    max_recent++;
                }
                else {
                    idx = findLRPage(capacity);
                    pages[idx] = arr[i];
                    recent[idx] = max_recent+1;
                    max_recent++;

                }
            }

        }

        printf("%d\n", pgf);


        
        
    }
	return 0;
}