#include<stdio.h> // Standard I/O
#define MAX 50 // Maximum edges/vertices

struct Edge{ int u, v, weight; }; // Edge structure

int find(int parent[], int i){ // Find set representative (root)
    while(parent[i] != i) i = parent[i]; // Path compression not used for simplicity
    return i;
}

void unionSet(int parent[], int x, int y){ // Union two disjoint sets
    int xset = find(parent, x); int yset = find(parent, y);
    parent[xset] = yset; // Attach root of x to root of y
}

int main(){
    struct Edge edges[MAX], temp; int parent[MAX]; int n, e;
    printf("Enter number of vertices:"); scanf("%d", &n); // Read vertices
    printf("Enter number of edges:"); scanf("%d", &e); // Read edges
    printf("Enter edges(u v weight):\n"); // Prompt for edge list
    for(int i = 0; i < e; i++){ scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight); }
    // Sort edges by weight ascending
    for(int i = 0; i < e - 1; i++){
        for(int j = i + 1; j < e; j++){
            if(edges[i].weight > edges[j].weight){
                temp = edges[i]; edges[i] = edges[j]; edges[j] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) parent[i] = i; // Initialize each vertex as its own parent
    int count = 0; int totalCost = 0;
    printf("Edges in Minimum Spanning Tree:\n"); // Output header
    for(int i = 0; i < e && count < n - 1; i++){ // Process edges until MST has n-1 edges
        int u = edges[i].u; int v = edges[i].v;
        int setU = find(parent, u); int setV = find(parent, v);
        if(setU != setV){ // If adding edge doesn't form a cycle
            printf("%d -- %d == %d\n", u, v, edges[i].weight); // Print edge
            totalCost += edges[i].weight; // Accumulate cost
            unionSet(parent, setU, setV); // Merge sets
            count++; // Increment MST edge count
        }
    }
    printf("Total cost of MST = %d\n", totalCost); // Output final cost
    return 0;
}