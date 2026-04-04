#include<stdio.h> // Standard I/O
#define INF 99999 // Large value representing no path
#define V 4 // Number of vertices

void floydWarshall(int graph[V][V]){
    int dist[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            dist[i][j] = graph[i][j]; // Initialize distance matrix
    for(int k = 0; k < V; k++){ // Intermediate vertex
        for(int i = 0; i < V; i++){ // Source vertex
            for(int j = 0; j < V; j++){ // Destination vertex
                if(dist[i][k] + dist[k][j] < dist[i][j]) // Relax edge if shorter path found
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printf("Shortest distances between every pair of vertices:\n"); // Output header
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(dist[i][j] == INF) printf("INF\t"); // Print INF if unreachable
            else printf("%d\t", dist[i][j]); // Print shortest distance
        }
        printf("\n"); // Newline after each row
    }
}

int main(){
    int graph[V][V] = { // Adjacency matrix with predefined weights
        {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}
    };
    floydWarshall(graph); // Compute all-pairs shortest paths
    return 0;
}