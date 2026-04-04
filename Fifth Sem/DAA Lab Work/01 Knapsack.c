#include<stdio.h> // Standard I/O

int max(int a, int b){ return (a > b) ? a : b; } // Helper to find maximum

int main(){
    int n, W;
    printf("Enter number of items:"); scanf("%d", &n); // Read item count
    int weight[n], value[n]; // Arrays for weights and values
    printf("Enter weights of items:\n"); // Prompt
    for(int i = 0; i < n; i++){ scanf("%d", &weight[i]); } // Read weights
    printf("Enter values of items:\n"); // Prompt
    for(int i = 0; i < n; i++){ scanf("%d", &value[i]); } // Read values
    printf("Enter capacity of knapsack:"); scanf("%d", &W); // Read max capacity
    int dp[n + 1][W + 1]; // DP table
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0) dp[i][w] = 0; // Base case: 0 items or 0 capacity
            else if(weight[i - 1] <= w) // If item fits, choose max of including/excluding
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else dp[i][w] = dp[i - 1][w]; // Item doesn't fit, carry forward previous value
        }
    }
    printf("Maximum profit: %d\n", dp[n][W]); // Output optimal value
    return 0;
}