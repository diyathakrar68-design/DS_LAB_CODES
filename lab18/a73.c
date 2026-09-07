// Write a menu driven program to implement following operations on the 
// Doubled Ended Queue using an Array 
//  Insert at front end, Insert at rear end 
//  Delete from front end, Delete from rear end 
//  Display all elements of the queue 
#include <stdio.h>
#define MAX 5
int DEQ[MAX];
int F = -1, R = -1;
void insertFront()
{
    int Y;

    // Overflow Condition
    if ((F == 0 && R == MAX - 1) || (F == R + 1))
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert at front: ");
    scanf("%d", &Y);

    // First Element
    if (F == -1)
    {
        F = R = 0;
    }
    else if (F == 0)
    {
        F = MAX - 1;
    }
    else
    {
        F--;
    }

    DEQ[F] = Y;
    printf("%d inserted at front successfully.\n", Y);
}
void insertRear()
{
    int Y;

    // Overflow Condition
    if ((F == 0 && R == MAX - 1) || (F == R + 1))
    {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter element to insert at rear: ");
    scanf("%d", &Y);

    // First Element
    if (F == -1)
    {
        F = R = 0;
    }
    else if (R == MAX - 1)
    {
        R = 0;
    }
    else
    {
        R++;
    }

    DEQ[R] = Y;
    printf("%d inserted at rear successfully.\n", Y);
}
void deleteFront()
{
    if (F == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted from front.\n", DEQ[F]);

    // If only one element
    if (F == R)
    {
        F = R = -1;
    }
    else if (F == MAX - 1)
    {
        F = 0;
    }
    else
    {
        F++;
    }
}
void deleteRear()
{
    if (F == -1)
    {
        printf("Queue Underflow!\n");
        return;
    }

    printf("%d deleted from rear.\n", DEQ[R]);

    // If only one element
    if (F == R)
    {
        F = R = -1;
    }
    else if (R == 0)
    {
        R = MAX - 1;
    }
    else
    {
        R--;
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
        printf("%d ", DEQ[i]);

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
        printf("1. Insert at front end\n");
        printf("2. Insert at rear end\n");
        printf("3. Delete from front end\n");
        printf("4. Delete from rear end\n");
        printf("5. Display all elements of the queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;
            case 2:
                insertRear();
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}