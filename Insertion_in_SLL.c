#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 1. Insert at the beginning
void insertAtBeginning(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

// 2. Insert at the end
void insertAtEnd(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Insert at any specific position (1-based index)
void insertAtPosition(struct Node** head, int val, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If inserting at position 1 (beginning)
    if (position == 1) {
        insertAtBeginning(head, val);
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node right before the target position
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", position);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to print the linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert at beginning: 10ṇ
    insertAtBeginning(&head, 10);
    // Insert at beginning: 5 -> 10
    insertAtBeginning(&head, 5);
    printf("After inserting at beginning: ");
    display(head);

    // Insert at end: 5 -> 10 -> 20
    insertAtEnd(&head, 20);
    // Insert at end: 5 -> 10 -> 20 -> 30
    insertAtEnd(&head, 30);
    printf("After inserting at end: ");
    display(head);

    // Insert at position 3: 5 -> 10 -> 15 -> 20 -> 30
    insertAtPosition(&head, 15, 3);
    printf("After inserting 15 at position 3: ");
    display(head);

    // Insert at position 1: 1 -> 5 -> 10 -> 15 -> 20 -> 30
    insertAtPosition(&head, 1, 1);
    printf("After inserting 1 at position 1: ");
    display(head);

    return 0;
}