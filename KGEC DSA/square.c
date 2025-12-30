#include <stdio.h>

int isSquareMatrix(int rows, int cols) {
    return (rows == cols);
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

int main() {
    int matrix1[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int matrix2[10][10] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int matrix3[10][10] = {
        {1, 2},
        {3, 4}
    };
    
    // Test square matrix (3x3)
    displayMatrix(matrix1, 3, 3);
    if (isSquareMatrix(3, 3)) {
        printf("This is a Square Matrix\n\n");
    } else {
        printf("This is NOT a Square Matrix\n\n");
    }
    
    // Test non-square matrix (3x4)
    displayMatrix(matrix2, 3, 4);
    if (isSquareMatrix(3, 4)) {
        printf("This is a Square Matrix\n\n");
    } else {
        printf("This is NOT a Square Matrix\n\n");
    }
    
    // Test square matrix (2x2)
    displayMatrix(matrix3, 2, 2);
    if (isSquareMatrix(2, 2)) {
        printf("This is a Square Matrix\n");
    } else {
        printf("This is NOT a Square Matrix\n");
    }
    
    return 0;
}