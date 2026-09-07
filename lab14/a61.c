// Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
// Now Chef wants to know if the given string is balanced or not.  
// If is balanced then print 1, otherwise print 0.  
// A balanced parenthesis string is defined as follows: 
//  The empty string is balanced 
//  If P is balanced then (P), {P}, [P] is also balanced 
//  if P and Q are balanced PQ is also balanced 
//  "([])", "({})[()]" are balanced parenthesis strings  
//  "([{]})", "())" are not balanced.
#include <stdio.h>
#include <string.h>

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

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;

    if (open == '{' && close == '}')
        return 1;

    if (open == '[' && close == ']')
        return 1;

    return 0;
}

int main()
{
    char str[N];
    int balanced = 1;

    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        // Opening bracket
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(ch);
        }

        // Closing bracket
        else
        {
            // Closing bracket without opening bracket
            if (top == -1)
            {
                balanced = 0;
                break;
            }

            char open = pop();

            // Brackets don't match
            if (!isMatching(open, ch))
            {
                balanced = 0;
                break;
            }
        }
    }

    // Stack should be empty at the end
    if (top != -1)
        balanced = 0;

    printf("%d", balanced);

    return 0;
}


