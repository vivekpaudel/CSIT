#include<stdio.h> // Standard I/O
#include<string.h> // String library

int max(int a, int b){ return (a > b) ? a : b; } // Max helper

int main(){
    char X[100], Y[100]; // Strings
    printf("Enter first string:"); scanf("%s", X); // Read string 1
    printf("Enter second string:"); scanf("%s", Y); // Read string 2
    int m = strlen(X); int n = strlen(Y); // Get lengths
    int LCS[m + 1][n + 1]; // DP table
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || j == 0) LCS[i][j] = 0; // Base case: empty string
            else if(X[i - 1] == Y[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1; // Match found
            else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]); // Take max of excluding char
        }
    }
    printf("Length of Longest Common Subsequence: %d\n", LCS[m][n]); // Output length
    int index = LCS[m][n]; char lcsStr[index + 1]; lcsStr[index] = '\0'; // Prepare string buffer
    int i = m, j = n;
    while(i > 0 && j > 0){ // Backtrack to construct LCS
        if(X[i - 1] == Y[j - 1]){ // If chars match
            lcsStr[index - 1] = X[i - 1]; // Add to result
            i--; j--; index--; // Move diagonally up
        } else if(LCS[i - 1][j] > LCS[i][j - 1]) i--; // Move up
        else j--; // Move left
    }
    printf("Longest Common Subsequence: %s\n", lcsStr); // Print constructed LCS
    return 0;
}