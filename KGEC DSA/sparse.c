#include <stdio.h>

int isSparseMatrix(int matrix[][10], int rows, int cols) {
    int totalElements = rows * cols;
    int zeroCount = 0;
    
    // Count zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    
    // A matrix is sparse if more than half elements are zero
    return (zeroCount > totalElements / 2);
}

void displayMatrix(int matrix[][10], int rows, int cols) {
    printf("Matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void analyzeMatrix(int matrix[][10], int rows, int cols) {
    int totalElements = rows * cols;
    int zeroCount = 0;
    int nonZeroCount = 0;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            } else {
                nonZeroCount++;
            }
        }
    }
    
    printf("Total elements: %d\n", totalElements);
    printf("Zero elements: %d\n", zeroCount);
    printf("Non-zero elements: %d\n", nonZeroCount);
    printf("Percentage of zeros: %.2f%%\n", (float)zeroCount * 100 / totalElements);
}

int main() {
    int matrix[10][10];
    int rows, cols;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display and analyze the matrix
    displayMatrix(matrix, rows, cols);
    analyzeMatrix(matrix, rows, cols);
    if (isSparseMatrix(matrix, rows, cols)) {
        printf("This is a Sparse Matrix\n");
    } else {
        printf("This is NOT a Sparse Matrix\n");
    }

    return 0;
}