AIM

To implement a stack data structure using a linked list in the C programming language, supporting basic stack operations such as push, pop, peek, and display.

✅ ALGORITHM
1. Data Structure

Define a structure Node with:

int data

pointer to next node (struct Node *next)

Use a pointer top to represent the top of the stack.

2. PUSH Operation

Aim: Insert an element at the top of the stack.

Algorithm:

Create a new node.

Set newnode->data = value.

Set newnode->next = top.

Update top = newnode.

3. POP Operation

Aim: Remove the topmost element from the stack.

Algorithm:

If top == NULL, stack is empty → underflow.

Store top in a temporary pointer.

Update top = top->next.

Free the temporary node.

4. PEEK Operation

Aim: Return the top element without deleting it.

Algorithm:

If top == NULL, stack is empty.

Otherwise, display top->data.

5. DISPLAY Operation

Aim: Print all elements in the stack.

Algorithm:

Start from top.

#include <stdio.h>
#include <stdlib.h>

// Create node for linked list
struct Node
{
    int data;
    struct Node *next; // To hold the address of next node
};

// To create a node and it returns address of newly created node
struct Node *CreateNode(int data)
{
    // STACK = (char *)malloc(MAX * sizeof(char));
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(struct Node **top, int data)
{
    struct Node *newElement = CreateNode(data);
    newElement->next = *top;
    *top = newElement;
    printf("Node with data %d pushed successfully  .\n", data);
}

void pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack is empty/underflow, pop operation can't be performed");
        return;
    }

    struct Node *temp = *top;
    *top = temp->next;
    printf("Element %d popped from stack.\n", temp->data);
    free(temp);
    return;
}

void DisplayStack(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }

    struct Node *temp;
    temp = top;
    printf("\nElements In Stack: [Top] ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    struct Node *top = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            DisplayStack(top);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
Traverse each node until NULL, printing the data.
