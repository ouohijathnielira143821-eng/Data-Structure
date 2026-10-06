#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

/* PUSH */
void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &value);

        top++;
        stack[top] = value;

        printf("Element pushed successfully.\n");
    }
}

/* POP */
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
    } else {
        printf("Deleted element = %d\n", stack[top]);
        top--;
    }
}

/* PRINT */
void print() {
    int i;

    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");

        for (i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

/* PEEK */
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element = %d\n", stack[top]);
    }
}

/* PEEP */
void peep() {
    int position;

    printf("Enter position from top: ");
    scanf("%d", &position);

    if (position <= 0 || position > top + 1) {
        printf("Invalid position.\n");
    } else {
        printf("Element = %d\n", stack[top - position + 1]);
    }
}

/* CHANGE */
void change() {
    int position, value;

    printf("Enter position from top: ");
    scanf("%d", &position);

    if (position <= 0 || position > top + 1) {
        printf("Invalid position.\n");
    } else {
        printf("Enter new value: ");
        scanf("%d", &value);

        stack[top - position + 1] = value;

        printf("Element changed successfully.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Peek\n");
        printf("5. Peep\n");
        printf("6. Change\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                print();
                break;

            case 4:
                peek();
                break;

            case 5:
                peep();
                break;

            case 6:
                change();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
