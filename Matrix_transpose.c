#include <stdio.h>

void displayMatrix(int r, int c, int mat[r][c]) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void transposeMatrix(int r, int c, int a[r][c], int trans[c][r]) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            trans[j][i] = a[i][j];
}

int main() {
    int r, c;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c], trans[c][r];

    printf("Enter Matrix:\n");
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) scanf("%d", &a[i][j]);

    transposeMatrix(r, c, a, trans);

    printf("Transposed Matrix:\n");
    displayMatrix(c, r, trans);
    return 0;
}