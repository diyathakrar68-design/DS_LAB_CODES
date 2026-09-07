//  Write a program to convert infix notation to prefix notation using stack.
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

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main()
{
    char infix[N], postfix[N], prefix[N];
    int i, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    // Step 1: Reverse infix
    reverse(infix);

    // Step 2: Swap brackets
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert modified expression to postfix
    for (i = 0; i < strlen(infix); i++)
    {
        char ch = infix[i];

        // Operand
        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j++] = pop();
            }

            pop();   // Remove '('
        }

        // Operator
        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   priority(peek()) > priority(ch))
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

    // Step 4: Reverse postfix to get prefix
    reverse(postfix);

    strcpy(prefix, postfix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}



