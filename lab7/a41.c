#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
void insert(int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = first;
    first = newNode;
    printf("%d", newNode->info);
    free(newNode);
}
void main()
{
    int value;
    printf("enter the value : ");
    scanf("%d", &value);
    insert(value);
}
