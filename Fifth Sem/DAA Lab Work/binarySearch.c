#include<stdio.h> // Include standard I/O library for input/output functions

// Function to perform binary search on a sorted array
int binarySearch(int arr[], int size, int key){
    int low = 0, high = size - 1; // Initialize search boundaries: low at start, high at end
    while(low <= high){ // Loop continues as long as the search space is valid
        int mid = (low + high) / 2; // Calculate the middle index of current range
        if(arr[mid] == key) // Check if middle element matches the key
            return mid; // Return index if found
        else if(arr[mid] < key) // If key is greater, discard left half
            low = mid + 1; // Move low to right of mid
        else // If key is smaller, discard right half
            high = mid - 1; // Move high to left of mid
    }
    return -1; // Return -1 if element is not present in the array
}

int main(){
    int arr[100], n, key, i, result; // Declare array, size, search key, loop var, and result
    printf("Enter number of elements:"); // Prompt user for array size
    scanf("%d", &n); // Read the number of elements
    printf("Enter %d sorted elements:\n", n); // Prompt user to enter sorted elements
    for(i = 0; i < n; i++){ // Loop to read n elements into the array
        scanf("%d", &arr[i]); // Store each element in arr[i]
    }
    printf("Enter element to search:"); // Prompt for the element to find
    scanf("%d", &key); // Read the search key
    result = binarySearch(arr, n, key); // Call binary search and store returned index
    if(result != -1) // Check if search was successful
        printf("Element found at index %d", result); // Print the found index
    else
        printf("Element not found"); // Print failure message
    return 0; // Terminate program successfully
}