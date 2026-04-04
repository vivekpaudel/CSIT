#include<stdio.h> // Standard I/O

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index
    if(left < n && arr[left] > arr[largest]) // If left child exists and is greater than root
        largest = left; // Update largest
    if(right < n && arr[right] > arr[largest]) // If right child exists and is greater than largest so far
        largest = right; // Update largest
    if(largest != i){ // If largest is not root
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp; // Swap root with largest
        heapify(arr, n, largest); // Recursively heapify affected subtree
    }
}

// Main heap sort function
void heapSort(int arr[], int n){
    for(int i = n / 2 - 1; i >= 0; i--) // Build max heap (start from last non-leaf node)
        heapify(arr, n, i);
    for(int i = n - 1; i > 0; i--){ // Extract elements one by one
        int temp = arr[0]; arr[0] = arr[i]; arr[i] = temp; // Move current root to end
        heapify(arr, i, 0); // Call heapify on reduced heap
    }
}

void printArray(int arr[], int n){ // Utility to print array
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[100], n;
    printf("Enter number of elements:"); scanf("%d", &n); // Read size
    printf("Enter %d elements:\n", n); // Prompt
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]); // Read elements
    heapSort(arr, n); // Sort array
    printf("Sorted array:\n"); printArray(arr, n); // Print result
    return 0;
}