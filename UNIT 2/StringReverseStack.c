#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char stack[MAX];
    char str[MAX];
    int top = -1;
    int i;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    /* Remove newline */
    str[strcspn(str, "\n")] = '\0';

    /* Push characters into stack */
    for (i = 0; str[i] != '\0'; i++) {
        top++;
        stack[top] = str[i];
    }

    printf("String in reverse order: ");

    /* Pop characters */
    while (top >= 0) {
        printf("%c", stack[top]);
        top--;
    }

    printf("\n");

    return 0;
}
