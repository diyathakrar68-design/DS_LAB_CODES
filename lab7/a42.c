#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *first = NULL;
void insertATFirst(int x)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = first;
    first = newNode;
    printf("%d", newNode->info);
    free(newNode);
}
void insertATlast(int x)
{
    struct node *newNode;
    struct node *SAVE;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first = NULL)
    {
        first = newNode;
    }
    else
    {
        SAVE = first;
        while (SAVE->link != NULL)
        {
            SAVE = SAVE->link;
        }
        SAVE->link = newNode;
    }
    printf("%d", newNode->info);
    free(newNode);
}
void deletenode(int x)
{
    struct node *newNode;
    struct node *SAVE;
    struct node *PRED;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->link = NULL;
    if (first = NULL)
    {
        first = newNode;
    }

    while (SAVE != x && SAVE->link != NULL)
    {
        PRED = SAVE;
        first->link = PRED;
        PRED->link = SAVE;
    }
    if (SAVE != x)
    {
        printf("node not found");
    }
    if (SAVE == first)
    {
        first = first->link;
    }
    else
    {
        PRED->link = SAVE->link;
    }
    free(SAVE);
}