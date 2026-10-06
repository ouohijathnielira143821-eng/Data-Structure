#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top < MAX - 1) {
        top++;
        stack[top] = value;
    }
}

int pop() {
    if (top >= 0) {
        return stack[top--];
    }

    return 0;
}

int main() {
    int n, i;
    long int factorial = 1;

    printf("Enter an integer: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not possible for negative numbers.\n");
        return 0;
    }

    /* Push numbers into stack */
    for (i = 1; i <= n; i++) {
        push(i);
    }

    /* Pop numbers and multiply */
    while (top >= 0) {
        factorial = factorial * pop();
    }

    printf("Factorial of %d = %ld\n", n, factorial);

    return 0;
}
