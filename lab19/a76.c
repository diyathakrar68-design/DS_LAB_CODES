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

int isSameTree(struct Node* root1, struct Node* root2)
{
    // Both trees are empty
    if (root1 == NULL && root2 == NULL)
        return 1;

    // One tree is empty and other is not
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Check data and recursively check left and right
    return (root1->data == root2->data &&
            isSameTree(root1->left, root2->left) &&
            isSameTree(root1->right, root2->right));
}

int main()
{
    struct Node *root1, *root2;

    // First tree
    root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->right = createNode(1);

    // Second tree
    root2 = createNode(3);
    root2->left = createNode(2);
    root2->right = createNode(4);
    root2->left->right = createNode(1);

    if (isSameTree(root1, root2))
        printf("Given trees are same");
    else
        printf("Given trees are not same");

    return 0;
}