#include<stdio.h> // Standard I/O
#include<stdlib.h> // Standard library

int N; // Global board size

void printBoard(int board[N][N]){ // Display current board configuration
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%c ", board[i][j] ? 'Q' : '.'); // Print Queen or empty cell
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col){ // Check if queen placement is safe
    int i, j;
    for(i = 0; i < col; i++) if(board[row][i]) return 0; // Check left in same row
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--) if(board[i][j]) return 0; // Check upper-left diagonal
    for(i = row, j = col; i < N && j >= 0; i++, j--) if(board[i][j]) return 0; // Check lower-left diagonal
    return 1; // Safe placement
}

int solveNQueensUtil(int board[N][N], int col){ // Recursive solver
    if(col >= N){ printBoard(board); return 1; } // All queens placed successfully
    int res = 0;
    for(int i = 0; i < N; i++){ // Try placing queen in all rows of current column
        if(isSafe(board, i, col)){
            board[i][col] = 1; // Place queen
            res = solveNQueensUtil(board, col + 1) || res; // Recurse for next column
            board[i][col] = 0; // Backtrack: remove queen
        }
    }
    return res;
}

void solveNQueens(){ // Wrapper function
    int board[N][N];
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) board[i][j] = 0; // Initialize board
    if(!solveNQueensUtil(board, 0)) printf("No solution exists.\n"); // Handle failure
}

int main(){
    printf("Enter the value of N (size of chessboard):"); scanf("%d", &N); // Read board size
    printf("Solutions for %d-Queens problem:\n\n", N); // Output header
    solveNQueens(); // Start solving
    return 0;
}