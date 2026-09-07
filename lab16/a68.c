//  Write a program for evaluation of prefix Expression using Stack. 

#include <stdio.h>
#include <ctype.h>

#define N 100

int stack[N];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char prefix[N];

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    // Scan from RIGHT to LEFT
    for (int i = 0; prefix[i] != '\0'; i++)
        ;

    int length = 0;

    while (prefix[length] != '\0')
        length++;

    for (int i = length - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        // If operand
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        // If operator
        else
        {
            int a = pop();
            int b = pop();
            int result;

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());

    return 0;
}

