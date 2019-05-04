int intersectPoint(struct Node* head1, struct Node* head2)
{
    // Your Code Here
    int lenP = 0;
    int lenQ = 0;
    struct Node* p = head1;
    struct Node* q = head2;
    while (head1->next) {
        head1 = head1->next;
        lenP++;
    }
    while (head2->next) {
        head2 = head2->next;
        lenQ++;
    }
    
    if (lenP > lenQ) {
        int diff = lenP-lenQ;
        while (diff--) {
            p = p->next;
        }
    }
    else {
        int diff = lenQ-lenP;
        while (diff--) {
            q = q->next;
        }
    }
    
    while (p && q && p!=q) {
        p = p->next;
        q = q->next;
    }
    
    if (!p || !q) {
        return -1;
    }
    
    if (p == q) return p->data;
}