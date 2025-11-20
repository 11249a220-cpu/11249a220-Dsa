Aim:

To write a C program that converts an infix expression (e.g., A+B*C) into a postfix expression (e.g., ABC*+) using stack operations.
This helps in easier expression evaluation by computers.

✅ Algorithm: Infix to Postfix Conversion:
Step 1: Initialize

Create an empty stack for operators.

Create an empty postfix string.

Step 2: Scan the Infix Expression

For each character ch in the infix expression:

Case A: Operand

If ch is an operand (A–Z, a–z, 0–9),
→ Append it to postfix.

Case B: Left Parenthesis (

Push it onto the stack.

Case C: Right Parenthesis )

Pop from stack and append to postfix until ( is found.

Remove the ( from stack.

*Case D: Operator (+, -, , /, ^)

While stack is not empty AND
precedence(top of stack) ≥ precedence(current operator),
→ Pop and append to postfix.

Push the current operator onto the stack.

Step 3: After Scanning

Pop all remaining operators from stack and append to postfix.

Step 4: End
#include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

void Display()
{
    printf("Current Stack elements are -");
    for (int i = 0; i <= TOP; i++)
    {
        printf("[%c,]", STACK[i]);
    }
    printf("\n");
}

void Push(char item)
{
    if (TOP == MAX - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char Pop()
{
    if (TOP == -1)
    {
        printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

char Peek()
{
    if (TOP == -1)
    {
        // printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1; // lowest precedence
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // highest precedence
    default:
        return 0; // consider it as operand
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX];
    char postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int TokenPrecedence, j = 0, i = 0;
    char c, temp;

    // Reading one token at a time
    while ((c = infix[i]) != '\0')
    // for (int i = 0; i < MAX; i++)
    {
        // c = infix[i];
        TokenPrecedence = GetPrecedence(c); // Current token at a time
        if (TokenPrecedence > 0)            // Current token is Operator
        {
            while (TokenPrecedence <= GetPrecedence(Peek())) // Current Token <= Stack Top Token
            {
                postfix[j++] = Pop();
            }
            Push(c);
        }
        else // Current token is operand or '(' or ')'
        {
            switch (c)
            {
            case '(':
                Push(c);
                break;
            case ')':
                while (Peek() != '(')
                {
                    postfix[j++] = Pop();
                }
                Pop();
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }

    // Pop All remaining tokens from stack
    while (Peek() != '\0')
    {
        char c = Pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is : %s", postfix);
    return 0;
}
The resulting string is the postfix expression.
