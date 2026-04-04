#include<stdio.h> // Standard I/O

// Partition function to place pivot in correct position
int partition(int arr[], int low, int high){
    int pivot = arr[high]; // Choose last element as pivot
    int i = low - 1; // Index of smaller element
    for(int j = low; j <= high - 1; j++){ // Iterate through array
        if(arr[j] <= pivot){ // If current element is smaller/equal to pivot
            i++; // Increment index of smaller element
            int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp; // Swap arr[i] and arr[j]
        }
    }
    int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp; // Place pivot in correct spot
    return i + 1; // Return pivot index
}

// Recursive quicksort function
void quickSort(int arr[], int low, int high){
    if(low < high){ // Base case
        int pi = partition(arr, low, high); // Get partition index
        quickSort(arr, low, pi - 1); // Recursively sort left subarray
        quickSort(arr, pi + 1, high); // Recursively sort right subarray
    }
}

int main(){
    int arr[100], n;
    printf("Enter number of elements:"); scanf("%d", &n); // Read size
    printf("Enter %d elements:\n", n); // Prompt
    for(int i = 0; i < n; i++){ scanf("%d", &arr[i]); } // Read elements
    quickSort(arr, 0, n - 1); // Sort entire array
    printf("Sorted array:\n"); // Output header
    for(int i = 0; i < n; i++){ printf("%d ", arr[i]); } // Print result
    printf("\n");
    return 0;
}