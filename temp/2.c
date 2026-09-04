#include <stdio.h>
#include <stdlib.h>

// Structure of a tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Inorder Traversal
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        // 2. Visit Left Subtree
        inorder(root->left);
        // 1. Visit Root
        printf("%d ", root->data);

        // 3. Visit Right Subtree
        inorder(root->right);
    }
}

int main()
{
    // Create the root
    struct Node *root = createNode(10);

    // Create left and right children
    root->left = createNode(20);
    root->right = createNode(30);

    // Create children of 20
    root->left->left = createNode(40);
    root->left->right = createNode(50);

    // Display Inorder Traversal
    printf("inorder Traversal: ");

    inorder(root);

    return 0;
}