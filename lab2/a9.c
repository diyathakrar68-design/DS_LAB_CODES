// WAP to find power of a number using loop
#include <stdio.h>
void main()
{
    int b, e, i;
    int ans = 1;
    printf("enter the base and exponent : ");
    scanf("%d %d", &b, &e);
    for (i = 1; i <= e; i++)
    {
        ans = ans * b;
    }
    printf("the answer is %d ", ans);
}