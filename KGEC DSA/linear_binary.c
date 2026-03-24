#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return index if found
        }
    }
    return -1; // Return -1 if not found
}

int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // Return index if found
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    
    // Linear Search
    int linear_result = linearSearch(arr, size, target);
    if (linear_result != -1) {
        printf("Linear Search: Element %d found at index %d\n", target, linear_result);
    } else {
        printf("Linear Search: Element %d not found\n", target);
    }
    
    
    int binary_result = binarySearch(arr, size, target);
    if (binary_result != -1) {
        printf("Binary Search: Element %d found at index %d\n", target, binary_result);
    } else {
        printf("Binary Search: Element %d not found\n", target);
    }
    
    return 0;
}
