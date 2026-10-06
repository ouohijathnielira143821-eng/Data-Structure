#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createList(int n)
{
    struct Node *head = NULL, *temp = NULL, *newNode;
    int i;

    for (i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
            head = newNode;
        else
            temp->next = newNode;

        temp = newNode;
    }

    return head;
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

struct Node* deleteFirst(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        return NULL;

    temp = head;
    head = head->next;
    free(temp);

    return head;
}

struct Node* deleteLast(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deleteSpecific(struct Node *head, int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node not found.\n");
        return head;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    return head;
}

int main()
{
    struct Node *head;
    int n, choice, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nOriginal List: ");
    display(head);

    printf("\n1. Delete First Node");
    printf("\n2. Delete Last Node");
    printf("\n3. Delete Specific Node");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        head = deleteFirst(head);
    else if (choice == 2)
        head = deleteLast(head);
    else if (choice == 3)
    {
        printf("Enter node to delete: ");
        scanf("%d", &value);
        head = deleteSpecific(head, value);
    }
    else
        printf("Invalid choice.\n");

    printf("Updated List: ");
    display(head);

    return 0;
}
