#include<stdio.h> // Standard I/O

// Recursive backtracking function to find subsets
void findSubsets(int set[], int n, int subset[], int subsetSize, int sum, int target, int index){
    if(sum == target){ // Base case: subset sum matches target
        printf("{");
        for(int i = 0; i < subsetSize; i++) printf("%d ", subset[i]); // Print elements
        printf("}\n");
        return;
    }
    if(index == n || sum > target) return; // Prune: out of bounds or sum exceeded
    subset[subsetSize] = set[index]; // Include current element
    findSubsets(set, n, subset, subsetSize + 1, sum + set[index], target, index + 1); // Recurse with inclusion
    findSubsets(set, n, subset, subsetSize, sum, target, index + 1); // Recurse without inclusion
}

int main(){
    int n, target;
    printf("Enter number of elements in the set:"); scanf("%d", &n); // Read size
    int set[n]; printf("Enter elements of the set:\n"); // Prompt
    for(int i = 0; i < n; i++) scanf("%d", &set[i]); // Read elements
    printf("Enter target sum:"); scanf("%d", &target); // Read target
    int subset[n]; // Temporary array for current subset
    printf("Subsets with sum %d are:\n", target); // Output header
    findSubsets(set, n, subset, 0, 0, target, 0); // Start recursion
    return 0;
}