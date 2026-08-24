#include <stdio.h>

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertBeginning(int arr[], int n, int val) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    return n + 1;
}

int insertEnd(int arr[], int n, int val) {
    arr[n] = val;
    return n + 1;
}

int insertAtPos(int arr[], int n, int val, int pos) {
    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    return n + 1;
}

int deleteBeginning(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty! Cannot delete.\n");
        return 0;
    }
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int deleteEnd(int arr[], int n) {
    if (n <= 0) {
        printf("Array is empty! Cannot delete.\n");
        return 0;
    }
    return n - 1;
}

int deleteAtPos(int arr[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int main() {
    int arr[100], n = 0, choice, val, pos;

    printf("Enter initial number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Display\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(arr, n);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                n = insertBeginning(arr, n, val);
                display(arr, n);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                n = insertEnd(arr, n, val);
                display(arr, n);
                break;
            case 4:
                printf("Enter value and index (0-based) to insert: ");
                scanf("%d %d", &val, &pos);
                n = insertAtPos(arr, n, val, pos);
                display(arr, n);
                break;
            case 5:
                n = deleteBeginning(arr, n);
                display(arr, n);
                break;
            case 6:
                n = deleteEnd(arr, n);
                display(arr, n);
                break;
            case 7:
                printf("Enter index (0-based) to delete: ");
                scanf("%d", &pos);
                n = deleteAtPos(arr, n, pos);
                display(arr, n);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}