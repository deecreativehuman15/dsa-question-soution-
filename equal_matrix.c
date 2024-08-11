#include <stdio.h>

int main() {
    int rows, cols;
    int areEqual = 1;  // Flag to check equality, assume they are equal initially

    // Get the number of rows and columns for the matrices
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix1[rows][cols], matrix2[rows][cols];

    // Input elements for the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    // Input elements for the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Compare the two matrices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                areEqual = 0;  // Set flag to 0 if any element differs
                break;
            }
        }
        if (!areEqual) {
            break;
        }
    }

    // Print the result
    if (areEqual) {
        printf("The two matrices are equal.\n");
    } else {
        printf("The two matrices are not equal.\n");
    }

    return 0;
}
