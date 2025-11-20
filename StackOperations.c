AIM

To implement a stack in C using an array and perform basic stack operations such as:

Push (insert an element)

Pop (remove an element)

Peek (view top element)

Display (print stack elements)

 ALGORITHMS 

1. PUSH Operation

Aim: Insert an element into the stack.

Algorithm

If top == size-1, print "Stack Overflow".

Else:

Increment top by 1.

Insert the new value into stack[top].

2. POP Operation

Aim: Remove the top element from the stack.

Algorithm

If top == -1, print "Stack Underflow".

Else:

Store or print stack[top].

Decrement top by 1.

3. PEEK Operation

Aim: Show the topmost element without removing it.

include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *STACK; // Dynamic Array

void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}

void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}

int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
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
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
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
Algorithm

If top == -1, print "Stack is Empty".

Else print stack[top].

4. DISPLAY Operation

Aim: Display all elements of the stack.

Algorithm

If top == -1, print "Stack is Empty".

Else:

For i = top to 0:

Print stack[i].
#include <stdio.h>
