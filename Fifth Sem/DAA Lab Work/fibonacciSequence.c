#include <stdio.h>

void printFibonacci(int n) {
    if (n <= 0) { printf("Please enter a positive integer.\n"); return; }
    
    long long a = 0, b = 1;
    printf("Fibonacci Sequence (%d terms): %lld", n, a);
    if (n == 1) { printf("\n"); return; }
    
    printf(" %lld", b);
    for (int i = 2; i < n; i++) {
        long long next = a + b;
        printf(" %lld", next);
        a = b;
        b = next;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of terms: ");
    if (scanf("%d", &n) == 1) printFibonacci(n);
    return 0;
}