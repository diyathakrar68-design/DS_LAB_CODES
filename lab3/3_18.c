#include <stdio.h>

void main()
{
    int n, i, sum = 0;
    float avg;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        sum = sum + i;
    }

    avg = (float)sum / n;

    printf("Average = %f", avg);
}