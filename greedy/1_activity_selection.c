#include <stdio.h>
#include <stdlib.h>
/*
Sort by end time.
Select non overlapping events.
*/

struct Event {
    int start;
    int end;
};

int compareEvents(const void* a, const void* b) {
    return ((struct Event *)a)->end  - ((struct Event *)b)->end;
}

int checkOverlap(struct Event a, struct Event b) {
    return (a.start < b.end && a.end > b.start);
}

struct Event arr[1000];

int main() {
	//code
    freopen("activity_selection.txt", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x;
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            arr[i].start = x;
        }

        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            arr[i].end = x;
        }

        qsort(arr, n, sizeof(struct Event), compareEvents);
        int count = 1;
        struct Event currEvent = arr[0];
        for (int i=1; i<n; i++) {
            if (!checkOverlap(currEvent, arr[i])) {
                count++;
                currEvent = arr[i];
            }
        }
        printf("%d\n", count);

    }
	return 0;
}