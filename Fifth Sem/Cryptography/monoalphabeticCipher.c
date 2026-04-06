/* ==========================================
   MONOALPHABETIC SUBSTITUTION CIPHER
   ========================================== */
#include <stdio.h>
#include <string.h>

// Substitution mapping table: [plaintext_char, ciphertext_char]
char alpha[26][2] = {
    {'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'}, {'e', 'n'},
    {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'},
    {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'},
    {'p', 't'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'},
    {'u', 'z'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'},
    {'z', 'h'}
};

// Function prototype
char monocipher_encr(char a);

int main() {
    char str[100], str2[100];
    int i;

    printf("\n Enter String: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Remove trailing newline

    // Encrypt each character by looking up the substitution table
    for(i = 0; str[i] != '\0'; i++) {
        str2[i] = monocipher_encr(str[i]);
    }
    str2[i] = '\0'; // Null-terminate the ciphertext

    printf("\n Original String: %s", str);
    printf("\n Encrypted String: %s\n", str2);

    return 0;
}

// Function to find the substitution character for a given input
char monocipher_encr(char a) {
    int i;
    // Linear search through the mapping table
    for(i = 0; i < 26; i++) {
        if(a == alpha[i][0]) break;
    }
    // Return mapped character if found, otherwise return original
    return (i < 26) ? alpha[i][1] : a;
}