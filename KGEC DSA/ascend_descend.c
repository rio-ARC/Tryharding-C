#include <stdio.h>

// Function to swap two integer values
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSortAscending(int arr[], int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        
        
        for (j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void bubbleSortDescending(int arr[], int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        
        
        for (j = 0; j < n - i - 1; j++) {
            
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int n, i;

    
    printf("Enter number of elements: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        
        while (getchar() != '\n');
    }

    int arr[n]; 

    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
         while (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Please enter an integer: ");
            
            while (getchar() != '\n');
        }
    }

    // --- Ascending Sort ---
    printf("\nOriginal array: \n");
    printArray(arr, n);

    // Create a copy for descending sort
    int arr_copy[n];
    for(i=0; i<n; i++) {
        arr_copy[i] = arr[i];
    }

    bubbleSortAscending(arr, n);

    printf("\nArray sorted in ascending order: \n");
    printArray(arr, n);


    // --- Descending Sort ---
    
    bubbleSortDescending(arr_copy, n);

    printf("\nArray sorted in descending order: \n");
    printArray(arr_copy, n);

    return 0;
}