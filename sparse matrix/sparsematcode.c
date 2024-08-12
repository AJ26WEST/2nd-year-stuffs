#include <stdio.h>

void main() {
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of cols: ");
    scanf("%d", &cols);
    
    int sparsematrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &sparsematrix[i][j]);
        }
    }

    int size = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparsematrix[i][j] != 0) {
                size++;
            }
        }
    }

    int tripletmatrix[size][3];
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparsematrix[i][j] != 0) {
                tripletmatrix[k][0] = i;
                tripletmatrix[k][1] = j;
                tripletmatrix[k][2] = sparsematrix[i][j];
                k++;
            }
        }
    }

    printf("The triplet matrix representation \n (row, col, value):\n");
    printf("  %d   %d    %d\n", rows, cols, size);
    for (int i = 0; i < size; i++) {
        printf("  %d   %d    %d\n", tripletmatrix[i][0], tripletmatrix[i][1], tripletmatrix[i][2]);
    }
}
