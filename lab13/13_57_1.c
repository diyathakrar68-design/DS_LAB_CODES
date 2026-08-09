#include <stdio.h>
#define N 3
int s[N];
int top = -1;
int pop()
{
    if (top == -1)
    {
        printf("stack is underflow ");
        return -1;
    }
    int x = s[top];
    top--;
    return x;
}
void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is Empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
}
void main()
{
    int i;
    s[++top] = 10;
    s[++top] = 20;
    s[++top] = 30;
    s[++top] = 40;
    printf("before pop:");
    display();
    pop();
    printf("after pop:");
    display();
    printf("the element is pop from stack :");
}