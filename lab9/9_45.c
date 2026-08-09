#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *insert(struct node *first, int value)
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->link = first;
    first = newNode;
    return first;
}
struct node *copy(struct node *first1, struct node *first2)
{
    while (first1 != NULL && first2 != NULL)
    {
        first2->info = first1->info;
        first1->link = first1;
        first2->link = first2;
    }
    if (first1 == NULL && first2 == NULL)
    {
        return 0;
    }
}
void main()
{
    struct node *first1 = NULL;
    struct node *first2 = NULL;
    int n, i;
    int value;
    int final_ans;
    printf("enter the no. of nodes :");
    scanf("%d", &n);

    printf("enter the elements of node1 : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        first1 = insert(first1, value);
    }
    first2=insert(first2,value);
    final_ans=(int)first2;
    printf("linkedlist is copied %d",final_ans);
}