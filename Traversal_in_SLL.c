#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverseAndDisplay(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Traversing list: ");
    while (current != NULL) {
        printf("[%d] ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 5;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 15;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 25;
    head->next->next->next = NULL;

    traverseAndDisplay(head);

    return 0;
}