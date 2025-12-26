#include <stdio.h>

void insertElement(int arr[], int *size, int element, int position) {
    // Shift elements to the right
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the element
    arr[position] = element;
    (*size)++;
}

void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size, element, position;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original ");
    displayArray(arr, size);

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert at (0-based index): ");
    scanf("%d", &position);

    if (position < 0 || position > size) {
        printf("Invalid position! Position should be between 0 and %d.\n", size);
        return 1;
    }

    // Insert the element
    insertElement(arr, &size, element, position);

    printf("After inserting %d at position %d: ", element, position);
    displayArray(arr, size);

    return 0;
}