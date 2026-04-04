#include<stdio.h> // Standard I/O

int gcd(int a, int b){ // Function to compute Greatest Common Divisor
    while(b != 0){ // Loop until remainder is 0
        int temp = b; // Store current divisor
        b = a % b; // Update divisor to remainder
        a = temp; // Update dividend to previous divisor
    }
    return a; // Return GCD
}

int main(){
    int num1, num2;
    printf("Enter two numbers:"); scanf("%d %d", &num1, &num2); // Read inputs
    int result = gcd(num1, num2); // Compute GCD
    printf("GCD of %d and %d is: %d\n", num1, num2, result); // Output result
    return 0;
}