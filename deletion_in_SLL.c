#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// 1. Delete from the beginning
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted %d from beginning.\n", temp->data);
    free(temp);
}

// 2. Delete from the end
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    // Only one node present
    if ((*head)->next == NULL) {
        printf("Deleted %d from end.\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    printf("Deleted %d from end.\n", temp->data);
    free(temp);
}

// 3. Delete from any specific position (1-based index)
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    // If deleting the first node
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Traverse to the node at the specified position
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of range.\n", position);
        return;
    }

    prev->next = temp->next;
    printf("Deleted %d from position %d.\n", temp->data, position);
    free(temp);
}

// Utility function to insert at the end for demonstration
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

    // Populate the list: 10 -> 20 -> 30 -> 40 -> 50
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Original List: ");
    display(head);

    // 1. Delete at beginning (removes 10)
    deleteAtBeginning(&head);
    printf("After deleting from beginning: ");
    display(head);

    // 2. Delete at end (removes 50)
    deleteAtEnd(&head);
    printf("After deleting from end: ");
    display(head);

    // 3. Delete at position 2 (removes 30 from: 20 -> 30 -> 40)
    deleteAtPosition(&head, 2);
    printf("After deleting at position 2: ");
    display(head);

    return 0;
}