/* ==========================================
   RAIL FENCE CIPHER
   ========================================== */
#include <stdio.h>
#include <string.h>

int main() {
    int i, j, len, rails, count;
    int code[100][1000] = {0}; // Matrix to simulate rail positions
    char str[1000];

    printf("Enter a Secret Message: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    len = strlen(str);

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    // Initialize matrix (redundant if declared with ={0}, but kept for clarity)
    for(i = 0; i < rails; i++) {
        for(j = 0; j < len; j++) {
            code[i][j] = 0;
        }
    }

    count = 0;
    j = 0;
    // Fill the matrix in a simplified zigzag pattern
    while(j < len) {
        if(count % 2 == 0) {
            // Move downwards through rails
            for(i = 0; i < rails && j < len; i++) {
                code[i][j] = (int)str[j];
                j++;
            }
        } else {
            // Move upwards (excluding top and bottom rails)
            for(i = rails - 2; i > 0 && j < len; i--) {
                code[i][j] = (int)str[j];
                j++;
            }
        }
        count++;
    }

    // Read ciphertext row by row
    printf("\nEncrypted Message: ");
    for(i = 0; i < rails; i++) {
        for(j = 0; j < len; j++) {
            if(code[i][j] != 0) {
                printf("%c", code[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}