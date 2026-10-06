#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct Node* insertAfter(struct Node *head, int specific, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL)
    {
        if (temp->data == specific)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->prev = temp;
            newNode->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = newNode;

            temp->next = newNode;

            return head;
        }

        temp = temp->next;
    }

    printf("Specific node not found.\n");
    return head;
}

struct Node* insertBefore(struct Node *head, int specific, int value)
{
    struct Node *temp = head;
    struct Node *newNode;

    while (temp != NULL)
    {
        if (temp->data == specific)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));

            newNode->data = value;
            newNode->next = temp;
            newNode->prev = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = newNode;
            else
                head = newNode;

            temp->prev = newNode;

            return head;
        }

        temp = temp->next;
    }

    printf("Specific node not found.\n");
    return head;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, i, value, specific, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\n1. Insert After");
    printf("\n2. Insert Before");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter specific node: ");
    scanf("%d", &specific);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (choice == 1)
        head = insertAfter(head, specific, value);
    else if (choice == 2)
        head = insertBefore(head, specific, value);
    else
        printf("Invalid choice.\n");

    printf("Updated List: ");
    display(head);

    return 0;
}
