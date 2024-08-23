#include <stdio.h>

int main() {
    int row1, col1, row2, col2, i, j, k;

    // Input dimensions of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    // Input dimensions of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Error! Column of the first matrix is not equal to row of the second matrix.\n");
        return -1;
    }

    int mat1[row1][col1], mat2[row2][col2], result[row1][col2];

    // Input the first matrix
    printf("Enter elements of the first matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input the second matrix
    printf("Enter elements of the second matrix:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Initialize the result matrix to zero
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            for (k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Display the result
    printf("Resultant matrix:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
