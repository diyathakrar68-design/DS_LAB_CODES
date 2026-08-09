// WAP to find whether a number is odd or even.
#include <stdio.h>
void main()
{
    int n;
    printf("enter the number : ");
    scanf("%d", &n);
    if (n % 2 == 0)
    {
        printf("the number is even %d", n);
    }
    else
    {
        printf("the number is odd %d", n);
    }
}