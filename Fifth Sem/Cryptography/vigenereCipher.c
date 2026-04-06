/* ==========================================
   VIGENÈRE CIPHER (POLYALPHABETIC SUBSTITUTION)
   ========================================== */
#include <stdio.h>
#include <stdlib.h>  // For exit()
#include <string.h>
#include <ctype.h>   // For toupper() & isalpha()

// Function prototypes
void encipher();
void decipher();

int main() {
    int option;

    while (1) {
        printf("\n==================================");
        printf("\n 1. Encipher (Encrypt)");
        printf("\n 2. Decipher (Decrypt)");
        printf("\n 3. Exit");
        printf("\n==================================");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        
        // Clear the newline character left in the input buffer by scanf
        getchar(); 

        if (option == 1) {
            encipher();
        } else if (option == 2) {
            decipher();
        } else if (option == 3) {
            printf("Exiting program...\n");
            exit(0);
        } else {
            printf("Invalid selection! Try again.\n");
        }
    }
    return 0;
}

// Function to encrypt plaintext using a repeating keyword
void encipher() {
    char plain[128], key[32];
    int i, j, key_len;

    printf("\nEnter the plaintext (max 127 chars): ");
    fgets(plain, sizeof(plain), stdin);
    plain[strcspn(plain, "\n")] = '\0'; // Safely remove trailing newline

    printf("Enter the key (max 31 chars): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';     // Safely remove trailing newline

    key_len = strlen(key);
    if (key_len == 0) {
        printf("Error: Key cannot be empty.\n");
        return;
    }

    printf("\nCiphertext: ");
    for (i = 0, j = 0; plain[i] != '\0'; i++) {
        // Leave non-alphabetic characters unchanged (spaces, punctuation, numbers)
        if (!isalpha(plain[i])) {
            printf("%c", plain[i]);
            continue;
        }

        // Wrap the key index if it reaches the end
        if (j >= key_len) {
            j = 0;
        }

        // Convert characters to 0-25 range (A=0, B=1, ..., Z=25)
        int p_val = toupper(plain[i]) - 'A';
        int k_val = toupper(key[j]) - 'A';

        // Vigenère Encryption Formula: C = (P + K) mod 26
        int c_val = (p_val + k_val) % 26;

        // Convert back to ASCII and print as uppercase
        printf("%c", c_val + 'A');

        // Advance key index only when an alphabetic character is processed
        j++;
    }
    printf("\n");
}

// Function to decrypt ciphertext using the same repeating keyword
void decipher() {
    char cipher[128], key[32];
    int i, j, key_len;

    printf("\nEnter the ciphertext (max 127 chars): ");
    fgets(cipher, sizeof(cipher), stdin);
    cipher[strcspn(cipher, "\n")] = '\0';

    printf("Enter the key (max 31 chars): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    key_len = strlen(key);
    if (key_len == 0) {
        printf("Error: Key cannot be empty.\n");
        return;
    }

    printf("\nPlaintext: ");
    for (i = 0, j = 0; cipher[i] != '\0'; i++) {
        if (!isalpha(cipher[i])) {
            printf("%c", cipher[i]);
            continue;
        }

        if (j >= key_len) {
            j = 0;
        }

        int c_val = toupper(cipher[i]) - 'A';
        int k_val = toupper(key[j]) - 'A';

        // Vigenère Decryption Formula: P = (C - K + 26) mod 26
        // Adding 26 ensures the result is never negative before modulo
        int p_val = (c_val - k_val + 26) % 26;

        printf("%c", p_val + 'A');
        j++;
    }
    printf("\n");
}