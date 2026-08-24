#include <stdio.h>

void display(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[100], n, key, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    printf("Enter element to search: ");
    scanf("%d", &key);

    index = binarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        printf("Element %d found at index %d (position %d).\n", key, index, index + 1);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}