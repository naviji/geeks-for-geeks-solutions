#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

int count = 0;

void insertFront(int element);
void insertBack(int element);
void printList();
void deleteList();

int getMiddle();
struct Node* reverse(struct Node* start);
void rotateCounterClockWise(struct Node** head, int k);
void rotateClockWise(struct Node** head, int k);

int main() {
    freopen("rotate.txt", "r", stdin);
    int t, n, x, k;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            insertBack(x);
        }
        scanf("%d", &k);

        printList();
        // printf("%d\n", count);
        rotateClockWise(&head, k);
        printList();

        // printf("%d\n", getMiddle());
        deleteList();
    }
}

void rotateCounterClockWise(struct Node** head_ref, int k) {
    struct Node* oldHead = *head_ref;

    struct Node* prev = NULL;
    struct Node* iter = *head_ref;
    if (iter == NULL) return;

    if (k==0) return;

    while (k>1) {
        k--;
        iter = iter->next;
    }

    if (iter->next == NULL) return;

    prev = iter;
    iter = iter->next;
    prev->next = NULL;

    *head_ref = iter;

    while (iter->next != NULL) {
        iter = iter->next;
    }

    iter->next = oldHead;
}
void rotateClockWise(struct Node** head_ref, int k) {
    struct Node*  oldHead = *head_ref;
    struct Node* front = *head_ref;
    struct Node* back = oldHead;

    if (front == NULL) return;
    if (k == 0) return;

    while (front->next != NULL && k--) {
        front = front->next;
    }

    if (front->next == NULL && k>0) {
        // k = length of linked list
        return;
    }

    while (front->next != NULL) {
        front = front->next;
        back = back->next;
    }

    *head_ref = back->next;
    back->next = NULL;

    front->next = oldHead;
}

struct Node* reverse(struct Node* start) {
    // struct Node* temp = start;
    // struct Node* newNode = 
    if (start == NULL) {
        return NULL;
    }

    if (start->next == NULL) {
        return start;
    }

    struct Node* newStart = reverse(start->next);
    start->next->next = start;
    start->next = NULL;
    return newStart;
}

int getMiddle() {
    struct Node* fast = head;
    struct Node* slow = head;
    if (head == NULL) {
        return -1;
    }

    while (fast && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;
}

void insertBack(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (tail == NULL) {
        // Linked list is empty.
        tail = newNode;
        tail->data = x;
        tail->next = NULL;
        head = tail;
    }
    else {
        newNode->data = x;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;

    }
    count++;

}


void deleteList() {
    struct Node* t = head;
    if (t == NULL) return;
    
    struct Node* temp;
    while (t->next != NULL) {
        temp = t;
        t = t->next;
        free(temp);
    }
    free(t);
    head = NULL;
    tail = NULL;
    count = 0;
}

void printList() {
    struct Node* t = head;
    if (t == NULL) {
        printf("List is empty!\n");
        return;
    }

    while (t->next != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }

    printf("%d\n", t->data);
}

void insertFront(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (head == NULL) {
        // Linked list is empty.
        head = newNode;
        head->data = x;
        head->next = NULL;
        tail = head;
    }
    else {
        newNode->data = x;
        newNode->next = head;
        head = newNode;
    }
    count++;
}