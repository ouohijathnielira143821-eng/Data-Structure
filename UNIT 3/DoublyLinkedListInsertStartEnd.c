#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* insertStart(struct Node *head, int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        return newNode;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

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
    int n, i, value;

    printf("Enter number of initial nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("\nOriginal List: ");
    display(head);

    printf("\nEnter value to insert at starting: ");
    scanf("%d", &value);
    head = insertStart(head, value);

    printf("After insertion at start: ");
    display(head);

    printf("\nEnter value to insert at end: ");
    scanf("%d", &value);
    head = insertEnd(head, value);

    printf("After insertion at end: ");
    display(head);

    return 0;
}
