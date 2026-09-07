//  Write a program to convert infix notation to postfix notation using stack.

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define N 100

char stack[N];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

char peek()
{
    return stack[top];
}

int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/' || ch == '%')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[N], postfix[N];
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (int i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // If operand, add directly to postfix
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // If opening bracket, push
        else if (ch == '(')
        {
            push(ch);
        }

        // If closing bracket, pop until '('
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            pop();   // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   priority(peek()) >= priority(ch))
            {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

