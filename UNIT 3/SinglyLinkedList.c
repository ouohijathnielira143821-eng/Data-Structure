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

// Display linked list
void display(struct Node *head)
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked list is empty.\n");
        return;
    }

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
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    head = createList(n);

    display(head);

    return 0;
}
