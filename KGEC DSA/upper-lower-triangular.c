#include <stdio.h>

int isUpperTriangular(int matrix[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return 0; // Not upper triangular
            }
        }
    }
    return 1; // Upper triangular
}

int isLowerTriangular(int matrix[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                return 0; // Not lower triangular
            }
        }
    }
    return 1; // Lower triangular
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
    int upper[10][10] = {
        {1, 2, 3},
        {0, 4, 5},
        {0, 0, 6}
    };
    
    int lower[10][10] = {
        {1, 0, 0},
        {2, 4, 0},
        {3, 5, 6}
    };
    
    int regular[10][10] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int n = 3;
    
    // Test upper triangular matrix
    displayMatrix(upper, n);
    if (isUpperTriangular(upper, n)) {
        printf("Matrix is Upper Triangular\n");
    } else {
        printf("Matrix is NOT Upper Triangular\n");
    }
    
    if (isLowerTriangular(upper, n)) {
        printf("Matrix is Lower Triangular\n\n");
    } else {
        printf("Matrix is NOT Lower Triangular\n\n");
    }
    
    // Test lower triangular matrix
    displayMatrix(lower, n);
    if (isUpperTriangular(lower, n)) {
        printf("Matrix is Upper Triangular\n");
    } else {
        printf("Matrix is NOT Upper Triangular\n");
    }
    
    if (isLowerTriangular(lower, n)) {
        printf("Matrix is Lower Triangular\n\n");
    } else {
        printf("Matrix is NOT Lower Triangular\n\n");
    }
    
    // Test regular matrix
    displayMatrix(regular, n);
    if (isUpperTriangular(regular, n)) {
        printf("Matrix is Upper Triangular\n");
    } else {
        printf("Matrix is NOT Upper Triangular\n");
    }
    
    if (isLowerTriangular(regular, n)) {
        printf("Matrix is Lower Triangular\n");
    } else {
        printf("Matrix is NOT Lower Triangular\n");
    }
    
    return 0;
}