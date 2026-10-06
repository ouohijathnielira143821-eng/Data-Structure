#include <stdio.h>

int main()
{
    int a, b, remainder;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    printf("GCD = %d\n", a);

    return 0;
}
