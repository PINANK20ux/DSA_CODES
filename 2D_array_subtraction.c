#include <stdio.h>

void displayMatrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void subtractMatrix(int r, int c, int a[r][c], int b[r][c], int res[r][c]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            res[i][j] = a[i][j] - b[i][j];
}

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], b[r][c], res[r][c];

    printf("Enter Matrix A:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &b[i][j]);

    subtractMatrix(r, c, a, b, res);

    printf("Result Matrix:\n");
    displayMatrix(r, c, res);
    return 0;
}