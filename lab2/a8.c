// WAP to find factorial of a number (Using Loop)
#include <stdio.h>
void main()
{
    int n, i;
    printf("enter the number : ");
    scanf("%d", &n);
    int mul = 1;
    for (i = 1; i <= n; i++)
    {
        mul = mul * i;
    }
    printf("factorial of a number is %d", mul);
}