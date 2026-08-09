// WAP to find factors of a given number
#include <stdio.h>
void main()
{
    int n;
    int i = 0;
    printf("enter the number :");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%d ", i);
        }
    }
}