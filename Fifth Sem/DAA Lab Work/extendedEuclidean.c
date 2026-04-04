#include<stdio.h> // Standard I/O

int extendedGCD(int a, int b, int* x, int* y){ // Finds x, y such that ax + by = gcd(a,b)
    if(a == 0){ // Base case: gcd(0, b) = b
        *x = 0; *y = 1; return b;
    }
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1); // Recursive call
    *x = y1 - (b / a) * x1; // Update x using results from recursion
    *y = x1; // Update y
    return gcd; // Return GCD
}

int main(){
    int a, b, x, y;
    printf("Enter two integers a and b:"); scanf("%d %d", &a, &b); // Read inputs
    int gcd = extendedGCD(a, b, &x, &y); // Compute extended GCD
    printf("GCD(%d, %d) = %d\n", a, b, gcd); // Print GCD
    printf("Coefficients x and y are: x = %d, y = %d\n", x, y); // Print coefficients
    printf("Verification: %d*%d + %d*%d = %d\n", a, x, b, y, a * x + b * y); // Verify equation
    return 0;
}