// #include <stdio.h>
// #define MAX 5

// int queue[MAX];
// int front = -1, rear = -1;

// // Enqueue Operation
// void enqueue()
// {
//     int value;

//     if (rear == MAX - 1)
//     {
//         printf("Queue Overflow!\n");
//         return;
//     }

//     printf("Enter the value to insert: ");
//     scanf("%d", &value);

//     if (front == -1)
//         front = 0;

//     rear++;
//     queue[rear] = value;

//     printf("%d inserted into the queue.\n", value);
// }

// // Dequeue Operation
// void dequeue()
// {
//     if (front == -1 || front > rear)
//     {
//         printf("Queue Underflow!\n");
//         return;
//     }

//     printf("%d deleted from the queue.\n", queue[front]);
//     front++;

//     if (front > rear)
//     {
//         front = rear = -1;
//     }
// }

// // Display Operation
// void display()
// {
//     int i;

//     if (front == -1)
//     {
//         printf("Queue is Empty!\n");
//         return;
//     }

//     printf("Queue Elements: ");
//     for (i = front; i <= rear; i++)
//     {
//         printf("%d ", queue[i]);
//     }
//     printf("\n");
// }

// // Main Function
// int main()
// {
//     int choice;

//     do
//     {
//         printf("\n===== QUEUE MENU =====\n");
//         printf("1. ENQUEUE\n");
//         printf("2. DEQUEUE\n");
//         printf("3. DISPLAY\n");
//         printf("4. EXIT\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//             case 1:
//                 enqueue();
//                 break;

//             case 2:
//                 dequeue();
//                 break;

//             case 3:
//                 display();
//                 break;

//             case 4:
//                 printf("Program Exited.\n");
//                 break;

//             default:
//                 printf("Invalid Choice!\n");
//         }

//     } while (choice != 4);

//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// // Node structure
// struct Node
// {
//     int data;
//     struct Node *next;
// };

// struct Node *front = NULL;
// struct Node *rear = NULL;

// // Enqueue Operation
// void enqueue()
// {
//     struct Node *newNode;
//     int value;

//     newNode = (struct Node *)malloc(sizeof(struct Node));

//     printf("Enter value: ");
//     scanf("%d", &value);

//     newNode->data = value;
//     newNode->next = NULL;

//     if (front == NULL)
//     {
//         front = rear = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//         rear = newNode;
//     }

//     printf("%d inserted into the queue.\n", value);
// }

// // Dequeue Operation
// void dequeue()
// {
//     struct Node *temp;

//     if (front == NULL)
//     {
//         printf("Queue Underflow!\n");
//         return;
//     }

//     temp = front;
//     printf("%d deleted from the queue.\n", front->data);

//     front = front->next;
//     free(temp);

//     if (front == NULL)
//     {
//         rear = NULL;
//     }
// }

// // Display Operation
// void display()
// {
//     struct Node *temp;

//     if (front == NULL)
//     {
//         printf("Queue is Empty!\n");
//         return;
//     }

//     temp = front;

//     printf("Queue Elements: ");

//     while (temp != NULL)
//     {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }

//     printf("\n");
// }

// // Main Function
// int main()
// {
//     int choice;

//     do
//     {
//         printf("\n===== QUEUE USING LINKED LIST =====\n");
//         printf("1. Enqueue\n");
//         printf("2. Dequeue\n");
//         printf("3. Display\n");
//         printf("4. Exit\n");

//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice)
//         {
//             case 1:
//                 enqueue();
//                 break;

//             case 2:
//                 dequeue();
//                 break;

//             case 3:
//                 display();
//                 break;

//             case 4:
//                 printf("Program Exited.\n");
//                 break;

//             default:
//                 printf("Invalid Choice!\n");
//         }

//     } while (choice != 4);

//     return 0;
// }
#include <stdio.h>
#define MAX 5

int Q[MAX];
int F = -1, R = -1;

// Insert (Enqueue)
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

// Delete (Dequeue)
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

// Display
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

// Main Function
int main()
{
    int choice;

    do
    {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
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
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}