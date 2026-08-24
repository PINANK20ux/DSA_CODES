#include <stdio.h>

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    printf("Enter element to search: ");
    scanf("%d", &key);

    index = linearSearch(arr, n, key);

    if (index != -1) {
        printf("Element %d found at index %d (position %d).\n", key, index, index + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}