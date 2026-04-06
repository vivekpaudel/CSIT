/* ==========================================
   CAESAR CIPHER - METHOD 1 (BASIC)
   ========================================== */
#include <stdio.h>
#include <string.h>

int main() {
    char plain_text[100], cipher_text[100];
    int key, i, length;

    printf("Enter the plain text: ");
    scanf("%s", plain_text);
    printf("Enter the key value: ");
    scanf("%d", &key);

    printf("\nThe plain text is: %s", plain_text);
    length = strlen(plain_text);

    // Encryption: Shift each character by 'key'
    printf("\nThe encrypted text is: ");
    for(i = 0; i < length; i++) {
        if(plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            cipher_text[i] = ((plain_text[i] - 'A' + key) % 26) + 'A';
        } else if(plain_text[i] >= 'a' && plain_text[i] <= 'z') {
            cipher_text[i] = ((plain_text[i] - 'a' + key) % 26) + 'a';
        } else {
            cipher_text[i] = plain_text[i]; // Keep non-alphabetic chars unchanged
        }
        printf("%c", cipher_text[i]);
    }
    cipher_text[i] = '\0';

    // Decryption: Reverse the shift
    printf("\nThe decrypted text is: ");
    for(i = 0; i < length; i++) {
        if(plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            plain_text[i] = ((cipher_text[i] - 'A' - key + 26) % 26) + 'A';
        } else if(plain_text[i] >= 'a' && plain_text[i] <= 'z') {
            plain_text[i] = ((cipher_text[i] - 'a' - key + 26) % 26) + 'a';
        } else {
            plain_text[i] = cipher_text[i];
        }
        printf("%c", plain_text[i]);
    }
    printf("\n");
    return 0;
}