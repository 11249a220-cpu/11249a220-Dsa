Aim:

To traverse a binary tree using Breadth First Search (BFS) technique and visit all nodes level by level.

Algorithm (BFS / Level Order Traversal in C):

Step 1: Start
Step 2: If the tree is empty, print “Tree is empty” and stop
Step 3: Create a queue and insert the root node into the queue
Step 4: Repeat the following steps while the queue is not empty:
    a) Remove (dequeue) a node from the front of the queue
    b) Display the data of the node
    c) If the left child exists, insert it into the queue
    d) If the right child exists, insert it into the queue
Step 5: Stop

  Program:
#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Queue implementation for Level Order Traversal / BFS


void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Empty
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}
