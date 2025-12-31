#include <stdio.h>

void traverseArray(int arr[], int size) {
    printf("Traversing array:\n");
    for (int i = 0; i < size; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }
}

void traverseReverse(int arr[], int size) {
    printf("Reverse traversal:\n");
    for (int i = size - 1; i >= 0; i--) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }
}

int main() {
    int arr[100];
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Forward traversal
    traverseArray(arr, size);

    printf("\n");

    // Reverse traversal
    traverseReverse(arr, size);

    return 0;
}