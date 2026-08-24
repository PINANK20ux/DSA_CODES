#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void mergeArrays(int a[], int n1, int b[], int n2, int res[]) {
    int k = 0;
    for (int i = 0; i < n1; i++) res[k++] = a[i];
    for (int j = 0; j < n2; j++) res[k++] = b[j];
}

int main() {
    int a[50], b[50], res[100], n1, n2;
    printf("Enter size and elements of first array: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) scanf("%d", &a[i]);

    printf("Enter size and elements of second array: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) scanf("%d", &b[i]);

    mergeArrays(a, n1, b, n2, res);

    printf("Merged array: ");
    display(res, n1 + n2);

    return 0;
}