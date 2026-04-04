#include<stdio.h> // Standard I/O
#define MAX 50
#define INF 9999 // Represent infinity for disconnected edges

int main(){
    int n, cost[MAX][MAX]; int visited[MAX] = {0}; int min, minCost = 0;
    int u = 0, v = 0;
    printf("Enter number of vertices:"); scanf("%d", &n); // Read vertices
    printf("Enter cost adjacency matrix:\n"); // Prompt for matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &cost[i][j]); // Read edge weight
            if(cost[i][j] == 0) cost[i][j] = INF; // Treat 0 as no connection
        }
    }
    visited[0] = 1; // Start from vertex 0
    printf("Edges in MST:\n"); // Output header
    for(int k = 0; k < n - 1; k++){ // Repeat n-1 times
        min = INF;
        for(int i = 0; i < n; i++){
            if(visited[i]){ // For every visited vertex
                for(int j = 0; j < n; j++){
                    if(!visited[j] && cost[i][j] < min){ // Find cheapest edge to unvisited
                        min = cost[i][j]; u = i; v = j;
                    }
                }
            }
        }
        printf("%d -- %d == %d\n", u, v, min); // Print selected edge
        minCost += min; // Add to total cost
        visited[v] = 1; // Mark new vertex as visited
    }
    printf("Total cost of MST = %d\n", minCost); // Output total
    return 0;
}