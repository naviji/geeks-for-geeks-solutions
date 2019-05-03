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

int main() {
    freopen("finding_middle_element.txt", "r", stdin);
    int t, n, x;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=0; i<n; i++) {
            scanf("%d", &x);
            insertBack(x);
        }
        printList();
        // printf("%d\n", count);
        printf("%d\n", getMiddle());
        deleteList();
    }
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