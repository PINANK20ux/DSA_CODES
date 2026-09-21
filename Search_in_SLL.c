#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int search(struct Node* head, int target) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == target) {
            return position; // 1-based index
        }
        temp = temp->next;
        position++;
    }
    return -1; // Not found
}

int main() {
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 12;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 45;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 78;
    head->next->next->next = NULL;

    int key = 45;
    int pos = search(head, key);

    if (pos != -1)
        printf("Element %d found at position %d.\n", key, pos);
    else
        printf("Element %d not found in the list.\n", key);

    return 0;
}