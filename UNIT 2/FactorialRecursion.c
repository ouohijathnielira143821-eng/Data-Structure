#include <stdio.h>

long int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

int main() {
    int n;
    long int result;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not possible for negative numbers.\n");
    } else {
        result = factorial(n);
        printf("Factorial of %d = %ld\n", n, result);
    }

    return 0;
}
