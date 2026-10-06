#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int main()
{
    int base, exponent, i;
    long long result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    for (i = 1; i <= exponent; i++)
    {
        push(base);
    }

    while (top != -1)
    {
        result = result * pop();
    }

    printf("%d^%d = %lld\n", base, exponent, result);

    return 0;
}
