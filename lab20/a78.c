#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data)
{
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(struct Node* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left),
                   height(root->right));
}

int isBalanced(struct Node* root)
{
    int leftHeight, rightHeight;

    if (root == NULL)
        return 1;

    leftHeight = height(root->left);
    rightHeight = height(root->right);

    // Difference should not be greater than 1
    if (abs(leftHeight - rightHeight) > 1)
        return 0;

    // Check left and right subtrees
    return isBalanced(root->left) &&
           isBalanced(root->right);
}

int main()
{
    struct Node* root;

    root = createNode(3);

    root->left = createNode(9);

    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    if (isBalanced(root))
        printf("TRUE");
    else
        printf("FALSE");

    return 0;
}