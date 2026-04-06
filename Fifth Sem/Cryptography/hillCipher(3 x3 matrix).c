/* ==========================================
   HILL CIPHER (3x3 MATRIX ENCRYPTION/DECRYPTION)
   ========================================== */
#include <iostream>
#include <cmath>
using namespace std;

// Global matrices
float encrypt[3][1] = {0}, decrypt[3][1] = {0};
float a[3][3], b[3][3], mes[3][1], c[3][3];

void encryption();   // Encrypts: C = (K * M) mod 26
void decryption();   // Decrypts: M = (K^-1 * C) mod 26
void getKeyMessage();// Gets key matrix & plaintext
void inverse();      // Computes matrix inverse via Gauss-Jordan

int main() {
    getKeyMessage();
    encryption();
    decryption();
    return 0;
}

// Collect user input for key matrix and 3-letter message
void getKeyMessage() {
    int i, j;
    char msg[4]; // 3 chars + null terminator

    cout << "Enter 3x3 matrix for key (Must be invertible modulo 26):\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cin >> a[i][j];
            c[i][j] = a[i][j]; // Preserve original for inverse calculation
        }
    }

    cout << "\nEnter a 3-letter string: ";
    cin >> msg;
    for(i = 0; i < 3; i++) {
        mes[i][0] = msg[i] - 97; // Convert 'a'-'z' to 0-25 range
    }
}

// Matrix multiplication & modulo operation for encryption
void encryption() {
    int i, j, k;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 1; j++) {
            encrypt[i][j] = 0;
            for(k = 0; k < 3; k++) {
                encrypt[i][j] += a[i][k] * mes[k][j];
            }
        }
    }

    cout << "\nEncrypted string is: ";
    for(i = 0; i < 3; i++) {
        // Apply modulo 26 and convert back to ASCII character
        cout << (char)(fmod(encrypt[i][0], 26) + 97);
    }
}

// Gauss-Jordan elimination to compute inverse matrix
void inverse() {
    int i, j, k;
    float p, q;

    // Initialize b as identity matrix
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            b[i][j] = (i == j) ? 1 : 0;
        }
    }

    // Perform row operations to transform c into identity & b into inverse
    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];
            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j] * q - p * c[k][j];
                    b[i][j] = b[i][j] * q - p * b[k][j];
                }
            }
        }
    }

    // Normalize diagonal elements to 1
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            b[i][j] = b[i][j] / c[i][i];
        }
    }

    cout << "\n\nInverse Matrix is:\n";
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
}

// Decrypt using inverse matrix
void decryption() {
    int i, j, k;
    inverse(); // Compute K^-1 first

    for(i = 0; i < 3; i++) {
        for(j = 0; j < 1; j++) {
            decrypt[i][j] = 0;
            for(k = 0; k < 3; k++) {
                decrypt[i][j] += b[i][k] * encrypt[k][j];
            }
        }
    }

    cout << "\nDecrypted string is: ";
    for(i = 0; i < 3; i++) {
        cout << (char)(fmod(decrypt[i][0], 26) + 97);
    }
    cout << "\n";
}