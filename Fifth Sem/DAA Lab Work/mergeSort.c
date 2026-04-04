#include<stdio.h> // Standard I/O

// Function to merge two sorted subarrays
void merge(int arr[], int low, int mid, int high){
    int i = low, j = mid + 1, k = 0; // Pointers for left subarray, right subarray, and temp array
    int temp[100]; // Temporary array to hold merged result
    while(i <= mid && j <= high){ // Compare elements from both halves
        if(arr[i] < arr[j]){ temp[k++] = arr[i++]; } // Pick smaller from left
        else{ temp[k++] = arr[j++]; } // Pick smaller from right
    }
    while(i <= mid){ temp[k++] = arr[i++]; } // Copy remaining left elements
    while(j <= high){ temp[k++] = arr[j++]; } // Copy remaining right elements
    for(i = low, k = 0; i <= high; i++, k++){ arr[i] = temp[k]; } // Copy back to original array
}

// Recursive function to sort the array
void mergeSort(int arr[], int low, int high){
    if(low < high){ // Base case: if range has more than 1 element
        int mid = (low + high) / 2; // Calculate midpoint
        mergeSort(arr, low, mid); // Recursively sort left half
        mergeSort(arr, mid + 1, high); // Recursively sort right half
        merge(arr, low, mid, high); // Merge the two sorted halves
    }
}

int main(){
    int arr[100], n;
    printf("Enter number of elements:"); scanf("%d", &n); // Read size
    printf("Enter %d elements:\n", n); // Prompt
    for(int i = 0; i < n; i++){ scanf("%d", &arr[i]); } // Read elements
    mergeSort(arr, 0, n - 1); // Start sorting from index 0 to n-1
    printf("Sorted array:\n"); // Output header
    for(int i = 0; i < n; i++){ printf("%d ", arr[i]); } // Print sorted array
    printf("\n");
    return 0;
}