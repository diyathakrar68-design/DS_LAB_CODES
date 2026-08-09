#include <stdio.h>

#define N 5

int s[N];
int top = -1;

void push(int x)
{
    if(top == N-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s[++top] = x;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return s[top--];
}

int peep(int pos)
{
    if(top-pos+1 < 0)
    {
        printf("Invalid Position\n");
        return -1;
    }

    return s[top-pos+1];
}

void change(int pos,int value)
{
    if(top-pos+1 < 0)
    {
        printf("Invalid Position\n");
        return;
    }

    s[top-pos+1]=value;
}

void display()
{
    int i;

    if(top==-1)
    {
        printf("Stack Empty\n");
        return;
    }

    printf("Stack : ");

    for(i=top;i>=0;i--)
        printf("%d ",s[i]);

    printf("\n");
}

int main()
{
    int value;

    push(34);
    push(45);
    push(67);
    push(78);

    display();

    printf("\nPop Operation\n");
    value = pop();
    printf("Deleted = %d\n",value);

    display();

    printf("\nPeep Operation\n");
    value = peep(2);
    printf("Element = %d\n",value);

    printf("\nChange Operation\n");
    change(2,90);

    display();

    return 0;
}