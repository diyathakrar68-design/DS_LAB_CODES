#include <stdio.h>

void main()
{
    int a[100], n, i, sum = 0;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", p + i);

    for (i = 0; i < n; i++)
        sum = sum + *(p + i);

    printf("Sum = %d", sum);
}