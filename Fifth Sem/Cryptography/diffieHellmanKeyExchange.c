/* ==========================================
   DIFFIE-HELLMAN KEY EXCHANGE ALGORITHM
   ========================================== */
#include <stdio.h>

// Modular exponentiation: (base^exponent) % modulus
long long int mod_exp(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;
    while(exponent > 0) {
        if(exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1; // Divide exponent by 2
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    long long int p, g;       // Public parameters
    long long int a, b;       // Private keys
    long long int A, B;       // Public keys
    long long int shared_secret_A, shared_secret_B;

    // Example public parameters
    p = 23; // Prime modulus
    g = 5;  // Generator

    // Private keys (normally randomly chosen & kept secret)
    a = 6;  // Alice's private key
    b = 15; // Bob's private key

    // Compute public keys
    A = mod_exp(g, a, p); // A = g^a mod p
    B = mod_exp(g, b, p); // B = g^b mod p

    // Compute shared secrets
    shared_secret_A = mod_exp(B, a, p); // s = B^a mod p
    shared_secret_B = mod_exp(A, b, p); // s = A^b mod p

    printf("Public parameters: p = %lld, g = %lld\n", p, g);
    printf("Private keys: a = %lld, b = %lld\n", a, b);
    printf("Public keys: A = %lld, B = %lld\n", A, B);
    printf("Shared secret (Alice): %lld\n", shared_secret_A);
    printf("Shared secret (Bob):   %lld\n", shared_secret_B);

    if(shared_secret_A == shared_secret_B) {
        printf("Key exchange successful! Shared secret: %lld\n", shared_secret_A);
    } else {
        printf("Key exchange failed!\n");
    }
    return 0;
}