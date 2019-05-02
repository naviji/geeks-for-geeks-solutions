#include <iostream>
#include <queue>

using namespace std;

int main() {
    freopen("kth_largest_element_stream.txt", "r", stdin);
    // min heap
    int t;
    scanf("%d", &t);
    
    while (t--) {
        priority_queue<int, vector<int>, greater<int> > pq;
        int k, n;
        scanf("%d %d", &k, &n);

        int x;
        int i;

        for (i=0; i<n; i++) {
            scanf("%d", &x);
            if (pq.size() < k) {
                pq.push(x);
            }
            else if (pq.size()>=k && x>pq.top()) {
                    pq.pop();
                    pq.push(x);
            }

            if (i<k-1) {
                printf("-1 ");
            }
            else {
                printf("%d ", pq.top());
            }
            
        }
        
        printf("\n");
        // pq.clear();

        
        
    }
    return 0;



}   