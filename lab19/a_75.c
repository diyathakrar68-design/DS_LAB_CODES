struct node
{
    int info;
    struct node *LPTR;
    struct node *RPTR;
};
#include <stdio.h>
#include <stdlib.h>
struct node *createNode(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->LPTR = NULL;
    newNode->RPTR = NULL;
    return newNode;
};
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->info = x;
        root->LPTR = NULL;
        root->RPTR = NULL;
    }
    else if (x < root->info)
        root->LPTR = insert(root->LPTR, x);
    else if (x > root->info)
        root->RPTR = insert(root->RPTR, x);
    else
        printf("Duplicate value not allowed: %d\n", x);
    return root;
}
struct node *search(struct node *root, int x)
{
    if (root == NULL || root->info == x)
        return root;
    else if (x < root->info)
        return search(root->LPTR, x);
    else
        return search(root->RPTR, x);
}
void preorder(struct node *root)
{
    if (root != 0)
    {
        printf("preorder");
        printf("%d", root->info);

        preorder(root->LPTR);

        preorder(root->RPTR);
    }
}
void inorder(struct node *root)
{
    if (root != 0)
    {
        printf("inorder");

        inorder(root->RPTR);

        printf("%d", root->info);

        inorder(root->LPTR);
    }
}
void postorder(struct node *root)
{
    if (root != 0)
    {
        printf("postorder");

        postorder(root->RPTR);

        postorder(root->LPTR);

        printf("%d", root->info);
    }
}
