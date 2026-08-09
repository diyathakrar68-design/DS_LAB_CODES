#include <stdio.h>
void main()
{
    int i, n;

    int sum;

    printf("enter the number : ");
    scanf("%d", &n);
    int temp = n;
    int num = n;
    while (temp != 1 && temp != 4)
    {
        sum = 0;

        while (temp > 0)
        {
            int rem = temp % 10;
            sum = sum + (rem * rem);
            temp = temp / 10;
        }

        temp = sum;
    }
    if (sum == 1)
    {
        printf("happy number");
    }
    else
    {
        printf("not a happy number");
    }
}