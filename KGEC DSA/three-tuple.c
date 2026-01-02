#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Tuple;

void displayMatrix(int matrix[][10], int rows, int cols) {
    printf("Original Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int createThreeTuple(int matrix[][10], int rows, int cols, Tuple tuples[]) {
    int k = 1; // Start from index 1, index 0 stores matrix info
    
    // Store matrix dimensions and number of non-zero elements
    tuples[0].row = rows;
    tuples[0].col = cols;
    tuples[0].value = 0; // Will be updated with count of non-zero elements
    
    // Store non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                tuples[k].row = i;
                tuples[k].col = j;
                tuples[k].value = matrix[i][j];
                k++;
            }
        }
    }
    
    tuples[0].value = k - 1; // Update count of non-zero elements
    return k; // Return total tuples (including header)
}

void displayThreeTuple(Tuple tuples[], int size) {
    printf("\nThree Tuple Representation:\n");
    printf("Index\tRow\tCol\tValue\n");
    printf("-----\t---\t---\t-----\n");
    
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d\t%d\t%d\t%d (Matrix Info: %dx%d, %d non-zero elements)\n", 
                   i, tuples[i].row, tuples[i].col, tuples[i].value,
                   tuples[i].row, tuples[i].col, tuples[i].value);
        } else {
            printf("%d\t%d\t%d\t%d\n", i, tuples[i].row, tuples[i].col, tuples[i].value);
        }
    }
}

void reconstructMatrix(Tuple tuples[], int result[][10]) {
    int rows = tuples[0].row;
    int cols = tuples[0].col;
    int nonZeroElements = tuples[0].value;
    
    // Initialize result matrix with zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = 0;
        }
    }
    
    // Fill non-zero elements
    for (int i = 1; i <= nonZeroElements; i++) {
        result[tuples[i].row][tuples[i].col] = tuples[i].value;
    }
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

    Tuple tuples[100]; // Array to store three tuples
    int reconstructed[10][10];

    // Display original matrix
    displayMatrix(matrix, rows, cols);

    // Create three tuple representation
    int tupleCount = createThreeTuple(matrix, rows, cols, tuples);

    // Display three tuple representation
    displayThreeTuple(tuples, tupleCount);

    // Reconstruct matrix from three tuple
    reconstructMatrix(tuples, reconstructed);

    printf("\nReconstructed Matrix:\n");
    displayMatrix(reconstructed, rows, cols);

    // Verify if reconstruction is correct
    printf("\nVerification: ");
    int isCorrect = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != reconstructed[i][j]) {
                isCorrect = 0;
                break;
            }
        }
        if (!isCorrect) break;
    }

    if (isCorrect) {
        printf("Reconstruction successful!\n");
    } else {
        printf("Reconstruction failed!\n");
    }

    return 0;
}