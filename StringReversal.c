AIM

To write a C program that reverses a given string using appropriate string manipulation techniques.

ALGORITHM (String Reversal in C)

Algorithm: Reverse a String

Start.

Read the input string.

Initialize two variables:

start = 0

end = length of string - 1

While start < end:

Swap the characters at positions start and end.

Increment start by 1.

Decrement end by 1.

After the loop, the string is reversed.

Display the reversed string.

  Program:
  #include <stdio.h>
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

char pop()
{
    char temp = STACK[top];
    top = top - 1;
    return temp;
}

int main()
{
    printf("Enter the size of string to reverse: ");
    scanf("%d", &size);
    char input[size];
    STACK = (char *)malloc(size * sizeof(char));
    printf("Enter the string of size %d to reverse: ", size);
    scanf("%s", &input);

    for (int i = 0; i <= size - 1; i++)
    {
        push(input[i]);
    }
    printf("Reversed string is - \n");
    for (int i = 0; i <= size - 1; i++)
    {
        printf("%c", pop());
    }
}
Stop.
