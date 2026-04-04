#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i; // Return index if found
    }
    return -1; // Not found
}

int main() {
    int arr[] = {12, 34, 5, 89, 23, 67};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = linearSearch(arr, size, target);
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found in array\n", target);
    
    return 0;
}