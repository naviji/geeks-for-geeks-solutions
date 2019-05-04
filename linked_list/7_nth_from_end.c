int getNthFromLast(struct Node *head, int n)
{
       // Your code here
       struct Node *q = head;
       while (q && n>0) {
           q = q->next;
           n--;
       }
       
       if (q == NULL && n>0) {
           return -1;
       }
       
       struct Node* p = head;
       while (q) {
           q = q->next;
           p = p->next;
       }
       
       return p->data;
}