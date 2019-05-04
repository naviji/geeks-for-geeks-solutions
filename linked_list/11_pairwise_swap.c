void pairWiseSwap(struct node *head)
{
  // The task is to complete this method
  while (head && head->next) {
      int temp = head->data;
      head->data = head->next->data;
      head->next->data = temp;
      
      head = head->next->next;
  }
}