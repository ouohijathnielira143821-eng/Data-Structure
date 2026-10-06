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

struct Node* deleteFirst(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        return NULL;

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    return head;
}

struct Node* deleteLast(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        return NULL;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);

    return head;
}

struct Node* deleteSpecific(struct Node *head, int value)
{
    struct Node *temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node not found.\n");
        return head;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

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
    int n, i, value, choice;

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

    printf("\n1. Delete First Node");
    printf("\n2. Delete Last Node");
    printf("\n3. Delete Specific Node");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        head = deleteFirst(head);
    }
    else if (choice == 2)
    {
        head = deleteLast(head);
    }
    else if (choice == 3)
    {
        printf("Enter node to delete: ");
        scanf("%d", &value);
        head = deleteSpecific(head, value);
    }
    else
    {
        printf("Invalid choice.\n");
    }

    printf("Updated List: ");
    display(head);

    return 0;
}
