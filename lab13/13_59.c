#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push operation
void push(char ch)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = ch;
}

// Pop operation
char pop()
{
    if(top == -1)
        return '\0';

    return stack[top--];
}

int main()
{
    char str[100];
    int i = 0;

    printf("Enter the string: ");
    scanf("%s", str);

    // Step 1: Push 'c' initially
    push('c');

    // Step 2: Push all characters before 'c'
    while(str[i] != 'c')
    {
        if(str[i] == '\0')
        {
            printf("Invalid String (No middle 'c')\n");
            return 0;
        }

        push(str[i]);
        i++;
    }

    // Skip the middle 'c'
    i++;

    // Step 3: Compare remaining characters with stack
    while(str[i] != '\0')
    {
        char x = pop();

        if(x != str[i])
        {
            printf("String is NOT Accepted.\n");
            return 0;
        }

        i++;
    }

    // Step 4: Check whether only initial 'c' remains
    if(top == 0 && stack[top] == 'c')
        printf("String is Accepted.\n");
    else
        printf("String is NOT Accepted.\n");

    return 0;
}