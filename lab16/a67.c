// Write a program for evaluation of postfix Expression using Stack. 
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
    char postfix[N];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // If operand
        if (isdigit(ch))
        {
            push(ch - '0');
        }

        // If operator
        else
        {
            int b = pop();
            int a = pop();
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

