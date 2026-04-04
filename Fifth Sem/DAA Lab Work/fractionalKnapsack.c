#include<stdio.h> // Standard I/O

struct Item{ // Structure to represent an item
    int profit; int weight; float ratio; // Store profit, weight, and profit/weight ratio
};

int main(){
    struct Item items[50], temp; // Array of items and temp for swapping
    int n, capacity; float totalProfit = 0.0; // Number of items, knapsack capacity, total profit
    printf("Enter number of items:"); scanf("%d", &n); // Read item count
    printf("Enter profits of items:\n"); // Prompt for profits
    for(int i = 0; i < n; i++){ scanf("%d", &items[i].profit); } // Read profits
    printf("Enter weights of items:\n"); // Prompt for weights
    for(int i = 0; i < n; i++){ // Read weights and compute ratio
        scanf("%d", &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight; // Calculate value density
    }
    printf("Enter knapsack capacity:"); scanf("%d", &capacity); // Read capacity
    // Sort items by ratio in descending order (Bubble Sort)
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(items[i].ratio < items[j].ratio){
                temp = items[i]; items[i] = items[j]; items[j] = temp; // Swap items
            }
        }
    }
    // Greedily pick items
    for(int i = 0; i < n; i++){
        if(capacity >= items[i].weight){ // If item fits completely
            capacity -= items[i].weight; // Reduce remaining capacity
            totalProfit += items[i].profit; // Add full profit
        } else { // If only fraction fits
            totalProfit += items[i].ratio * capacity; // Add fractional profit
            break; // Knapsack is full
        }
    }
    printf("Maximum profit = %.2f\n", totalProfit); // Output result
    return 0;
}