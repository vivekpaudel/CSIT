#include<stdio.h> // Include standard I/O library

// Function to find minimum and maximum elements with reduced comparisons
void findMinMax(int arr[], int n, int* min, int* max){
    int i; // Loop counter
    if(n % 2 == 0){ // Check if array length is even
        if(arr[0] < arr[1]){ // Compare first two elements
            *min = arr[0]; *max = arr[1]; // Set min and max accordingly
        } else {
            *min = arr[1]; *max = arr[0]; // Swap assignment if reversed
        }
        i = 2; // Start pairwise comparison from index 2
    } else { // If array length is odd
        *min = arr[0]; *max = arr[0]; // Initialize both to first element
        i = 1; // Start pairwise comparison from index 1
    }
    while(i < n - 1){ // Process elements in pairs until second-to-last
        if(arr[i] < arr[i+1]){ // Compare current pair
            if(arr[i] < *min) // Update min if smaller
                *min = arr[i];
            if(arr[i+1] > *max) // Update max if larger
                *max = arr[i+1];
        } else {
            if(arr[i+1] < *min) // Check second element for min
                *min = arr[i+1];
            if(arr[i] > *max) // Check first element for max
                *max = arr[i];
        }
        i += 2; // Move to next pair
    }
}

int main(){
    int arr[100], n, i; // Array, size, loop counter
    int min, max; // Variables to store results
    printf("Enter number of elements:"); scanf("%d", &n); // Read size
    printf("Enter %d elements:\n", n); // Prompt for input
    for(i = 0; i < n; i++){ scanf("%d", &arr[i]); } // Read elements
    findMinMax(arr, n, &min, &max); // Call function, pass addresses for update
    printf("Minimum element = %d\n", min); // Print minimum
    printf("Maximum element = %d\n", max); // Print maximum
    return 0;
}