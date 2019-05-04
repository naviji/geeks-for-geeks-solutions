void removeTheLoop(struct Node *head)
{
     //Your code here
     struct Node* fast = head;
     struct Node* slow = head;
     
     int flag = 0;
     while (fast && slow && fast->next) {
         fast = fast->next->next;
         slow = slow->next;
         if (fast == slow) {
             flag = 1;
             break;
         }
     }
     
     if (!flag) {
         // no loop.
         return;
     }
     
     // found a loop;
     fast = head;
     while (fast->next != slow->next) {
         fast = fast->next;
         slow = slow->next;
     }
     
     // remove loop
     slow->next = NULL;
}