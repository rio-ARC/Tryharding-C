#include <stdio.h>

int isSymmetric(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                return 0; // Not symmetric
            }
        }
    }
    return 1; // Symmetric
}

void displayMatrix(int matrix[][10], int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix1[10][10] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    
    int matrix2[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int n = 3;
    
    // Test symmetric matrix
    displayMatrix(matrix1, n);
    if (isSymmetric(matrix1, n)) {
        printf("Matrix is Symmetric\n\n");
    } else {
        printf("Matrix is Not Symmetric\n\n");
    }
    
    // Test non-symmetric matrix
    displayMatrix(matrix2, n);
    if (isSymmetric(matrix2, n)) {
        printf("Matrix is Symmetric\n");
    } else {
        printf("Matrix is Not Symmetric\n");
    }
    
    return 0;
}