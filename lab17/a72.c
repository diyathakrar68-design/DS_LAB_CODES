//  Write a menu driven program to implement following operations on a circular 
// queue using an Array 
//  Insert 
//  Delete 
//  Display all elements of the queue 
#include <stdio.h>
#define MAX 5
int Q[MAX];
int F = -1, R = -1;
void insert()
{
    int Y;

    // Overflow Condition
    if ((R + 1) % MAX == F)
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &Y);

    // Move Rear
    R = (R + 1) % MAX;

    // Insert Element
    Q[R] = Y;

    // First Element
    if (F == -1)
        F = 0;

    printf("%d inserted successfully.\n", Y);
}
void delete()
{
    if (F == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted.\n", Q[F]);

    // If only one element
    if (F == R)
    {
        F = R = -1;
    }
    else
    {
        F = (F + 1) % MAX;
    }
}
void display()
{
    int i;

    if (F == -1)
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue Elements: ");

    i = F;

    while (1)
    {
        printf("%d ", Q[i]);

        if (i == R)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}
int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}