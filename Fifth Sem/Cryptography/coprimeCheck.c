/* ==========================================
   CO-PRIME NUMBER CHECK
   ========================================== */
#include <stdio.h>

int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Two numbers are co-prime if their GCD is exactly 1
int are_coprime(int num1, int num2) {
    return gcd(num1, num2) == 1;
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    if(are_coprime(num1, num2)) {
        printf("%d and %d are co-prime.\n", num1, num2);
    } else {
        printf("%d and %d are not co-prime.\n", num1, num2);
    }
    return 0;
}