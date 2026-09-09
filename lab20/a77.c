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

int isMirror(struct Node* root1, struct Node* root2)
{
    // Both are NULL
    if (root1 == NULL && root2 == NULL)
        return 1;

    // One is NULL
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Compare values and mirror children
    return (root1->data == root2->data &&
            isMirror(root1->left, root2->right) &&
            isMirror(root1->right, root2->left));
}



int main()
{
    struct Node* root;
    root = createNode(8);

    root->left = createNode(5);
    root->right = createNode(5);

    root->left->left = createNode(3);
    root->left->right = createNode(6);

    root->right->left = createNode(6);
    root->right->right = createNode(3);

    if (isMirror(root->left, root->right))
        printf("Given tree is symmetric");
    else
        printf("Given tree is not symmetric");

    return 0;
}