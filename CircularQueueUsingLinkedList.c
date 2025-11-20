AIM:

To implement a Circular Queue using a linked list in C and perform the basic queue operations:

Enqueue (insert element at rear)

Dequeue (remove element from front)

Peek (view front element)

Display (show all elements in circular order)

 ALGORITHMS (Circular Queue Using Linked List)

Let the circular queue be represented using:

struct Node { int data; struct Node* next; }

front → pointer to first node

rear → pointer to last node

rear->next always points to front to maintain circularity

1. ENQUEUE Operation

Aim: Insert an element at the rear of the circular queue.

Algorithm

Create a new node newnode.

Set newnode->data = value.

If queue is empty (front == NULL):

Set front = newnode.

Set rear = newnode.

Set newnode->next = front (circular link).

Else:

Set rear->next = newnode.

Set newnode->next = front.

Update rear = newnode.

2. DEQUEUE Operation

Aim: Remove an element from the front of the queue.

Algorithm

If queue is empty (front == NULL):

Print "Queue Underflow".

Exit.

If there is only one element (front == rear):

Print front->data.

Free front.

Set front = rear = NULL.

Else:

Create a temporary pointer temp = front.

Print temp->data.

Update front = front->next.

Set rear->next = front (maintain circular link).

Free temp.

3. PEEK Operation

Aim: Display the front element.

Algorithm

If queue is empty (front == NULL):

Print "Queue is Empty".

Else:

Print front->data.

4. DISPLAY Operation

Aim: Traverse and print all elements of the circular queue.

Algorithm

If queue is empty:

Print "Queue is Empty".

Stop.

Set temp = front.

Repeat:

Print temp->data.

Move temp = temp->next.

Until temp == front (one full cycle).

  program:

  #include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (front == NULL && rear == NULL) //Queue empty
    {
        front = rear = newNode;
        newNode->next = front; //Circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }

    printf("%d inserted into circular queue.\n", item);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) // Only one node
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display operation
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
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
✅ C Program: Circular Queue Using Linked List
