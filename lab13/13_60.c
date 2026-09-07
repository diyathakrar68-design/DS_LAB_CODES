#include <stdio.h>
#include <string.h>

#define N 5

int s[N];
int top = -1;

void push(char x)
{
    if (top == N - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    top--;
}

int main()
{
    char str[100];

    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        if (ch == 'a')
        {
            push(ch);
        }
        else
        {
            pop();
        }
    }

    if (top == -1)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Invalid\n");
    }

    return 0;
}