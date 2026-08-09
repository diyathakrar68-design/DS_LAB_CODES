#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

// Function to insert at the beginning
struct node *insert(struct node *first, int value)
{
    struct node *newNode;

    newNode = (struct node *)malloc(sizeof(struct node));

    newNode->info = value;
    newNode->link = first;
    first = newNode;

    return first;
}

// Function to compare two linked lists
int compare(struct node *first1, struct node *first2)
{
    while (first1 != NULL && first2 != NULL)
    {
        if (first1->info != first2->info)
            return 0; // Lists are different

        first1 = first1->link;
        first2 = first2->link;
    }

    if (first1 == NULL && first2 == NULL)
        return 1; // Lists are same

    return 0; // Lengths are different
}

int main()
{
    struct node *first1 = NULL;
    struct node *first2 = NULL;
    int n, value, i;

    // First list
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        first1 = insert(first1, value);
    }

    // Second list
    printf("Enter number of nodes in second list: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        first2 = insert(first2, value);
    }

    // Compare
    if (compare(first1, first2))
        printf("Both linked lists are SAME.\n");
    else
        printf("Both linked lists are DIFFERENT.\n");

    return 0;
}