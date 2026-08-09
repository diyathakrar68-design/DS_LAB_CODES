#include<stdio.h>
#include<string.h>
#define N 5
void main(){
    int top=-1;
    int s[top];
    
    for ( int i = 0; i < strlen(s); i++)
    {
        char ch = s[i];
        if(ch=='a'){
            push(ch);
        }
        else {
            pop();
        }
    }
    if(top!=-1){
        printf("invalid");
    }
    
}
void push(int x,top=)
{
    if(top == N-1)
    {
        printf("Stack Overflow\n");
        return;
    }

    s[++top] = x;
}