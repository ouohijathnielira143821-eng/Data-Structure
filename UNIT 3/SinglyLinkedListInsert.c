#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Create linked list
struct Node* createList(int n)
{
    struct Node *head = NULL;
    struct Node *temp = NULL;
    struct Node *newNode;
    int i;

    for (i = 1; i <= n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data for node %d: ", i);
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}

// Insert after a specific node
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
            newNode->next = temp->next;
            temp->next = newNode;

            printf("Node inserted after %d.\n", specific);
            return head;
        }

        temp = temp->next;
    }

    printf("Specific node not found.\n");
    return head;
}

// Insert before a specific node
struct Node* insertBefore(struct Node *head, int specific, int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    struct Node *newNode;

    while (temp != NULL)
    {
        if (temp->data == specific)
        {
            newNode = (struct Node*)malloc(sizeof(struct Node));

            newNode->data = value;

            if (prev == NULL)
            {
                newNode->next = head;
                head = newNode;
            }
            else
            {
                newNode->next = temp;
                prev->next = newNode;
            }

            printf("Node inserted before %d.\n", specific);
            return head;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Specific node not found.\n");
    return head;
}

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct Node *head;
    int n, choice;
    int specific, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    printf("\nOriginal ");
    display(head);

    printf("\n1. Insert after specific node");
    printf("\n2. Insert before specific node");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter specific node: ");
    scanf("%d", &specific);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (choice == 1)
    {
        head = insertAfter(head, specific, value);
    }
    else if (choice == 2)
    {
        head = insertBefore(head, specific, value);
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }

    display(head);

    return 0;
}
