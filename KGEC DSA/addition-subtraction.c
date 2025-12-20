#include <stdio.h>

void displayMatrix(int matrix[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrixAddition(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void matrixSubtraction(int a[][10], int b[][10], int result[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
}

void matrixMultiplication(int a[][10], int b[][10], int result[][10], int r1, int c1, int c2) {
    // Initialize result matrix
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0;
        }
    }
    
    // Multiplication
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrixTranspose(int matrix[][10], int transpose[][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int a[10][10] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int b[10][10] = {
        {7, 8, 9},
        {10, 11, 12}
    };
    
    int c[10][10] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    
    int result[10][10];
    int transpose[10][10];
    
    printf("Matrix A:\n");
    displayMatrix(a, 2, 3);
    
    printf("\nMatrix B:\n");
    displayMatrix(b, 2, 3);
    
    // Addition
    printf("\nMatrix Addition (A + B):\n");
    matrixAddition(a, b, result, 2, 3);
    displayMatrix(result, 2, 3);
    
    // Subtraction
    printf("\nMatrix Subtraction (A - B):\n");
    matrixSubtraction(a, b, result, 2, 3);
    displayMatrix(result, 2, 3);
    
    // Multiplication
    printf("\nMatrix C:\n");
    displayMatrix(c, 3, 2);
    
    printf("\nMatrix Multiplication (A * C):\n");
    matrixMultiplication(a, c, result, 2, 3, 2);
    displayMatrix(result, 2, 2);
    
    // Transpose
    printf("\nTranspose of Matrix A:\n");
    matrixTranspose(a, transpose, 2, 3);
    displayMatrix(transpose, 3, 2);
    
    return 0;
}