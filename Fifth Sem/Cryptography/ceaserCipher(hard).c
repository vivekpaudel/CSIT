/* ==========================================
   CAESAR CIPHER - METHOD 2 (ADVANCED WITH MENU)
   ========================================== */
#include <stdio.h>
#include <string.h>

char* encryption(char msg[]);
void decryption(char cipher_text[]);

int main() {
    int choice, flag = 0;
    char msg[255];
    char *c_text = NULL;

    printf("Enter plain text: ");
    fgets(msg, sizeof(msg), stdin);
    msg[strcspn(msg, "\n")] = '\0';
    printf("\nYour plain text message is: %s", msg);

    do {
        printf("\nPress 1 for Encryption\nPress 2 for Decryption\nPress 0 for Exit\nChoice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch(choice) {
            case 1:
                c_text = encryption(msg);
                flag = 1;
                break;
            case 2:
                if(flag == 1 && c_text != NULL) {
                    decryption(c_text);
                } else {
                    printf("First perform encryption process.\n");
                }
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Please enter a valid choice.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}

char* encryption(char cipher_text[]) {
    int key, i, len = strlen(cipher_text);
    printf("Enter the key for encryption: ");
    scanf("%d", &key);
    getchar();

    for(i = 0; i < len; i++) {
        if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z') {
            cipher_text[i] = ((cipher_text[i] - 'a' + key) % 26) + 'a';
        }
    }
    printf("Your encrypted msg is: %s\n", cipher_text);
    return cipher_text;
}

void decryption(char cipher_text[]) {
    int i, key;
    char temp[255];
    int len = strlen(cipher_text);

    printf("\nDecryption Process (Brute Force Shift 1-26):\n");
    for(key = 1; key <= 26; key++) {
        for(i = 0; i < len; i++) {
            if(cipher_text[i] >= 'a' && cipher_text[i] <= 'z') {
                temp[i] = ((cipher_text[i] - 'a' - key + 26) % 26) + 'a';
            } else {
                temp[i] = cipher_text[i];
            }
        }
        temp[i] = '\0';
        printf("\nShift %2d: %s", key, temp);
    }
    printf("\n");
}