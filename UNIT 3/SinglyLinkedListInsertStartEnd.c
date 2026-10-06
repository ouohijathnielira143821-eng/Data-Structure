#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Insert at starting
struct Node* insertStart(struct Node *head, int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node *head, int value)
{
    struct Node *newNode, *temp;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Display list
void display(struct Node *head)
{
    printf("Linked List: ");

    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial list
    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &value);

        head = insertEnd(head, value);
    }

    printf("\nOriginal ");
    display(head);

    // Insert at starting
    printf("\nEnter value to insert at starting: ");
    scanf("%d", &value);

    head = insertStart(head, value);

    printf("After inserting at starting:\n");
    display(head);

    // Insert at end
    printf("\nEnter value to insert at end: ");
    scanf("%d", &value);

    head = insertEnd(head, value);

    printf("After inserting at end:\n");
    display(head);

    return 0;
}
