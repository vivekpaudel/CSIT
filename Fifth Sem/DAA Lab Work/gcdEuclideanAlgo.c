#include <stdio.h>
#include <stdlib.h>

/**
 * Computes the GCD of two integers using the Euclidean Algorithm.
 * Time Complexity: O(log(min(a, b)))
 * Space Complexity: O(1)
 */
int gcd(int a, int b) {
    // Work with absolute values to handle negative inputs
    a = abs(a);
    b = abs(b);

    // Euclidean Algorithm (iterative)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }

    // GCD(0, 0) is mathematically undefined
    if (num1 == 0 && num2 == 0) {
        printf("GCD is undefined for two zeros.\n");
        return 0;
    }

    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    return 0;
}