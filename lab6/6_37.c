#include <stdio.h>

void main()
{
    int a[100], n, i;
    int *p, largest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", p + i);

    largest = *p;

    for (i = 1; i < n; i++)
    {
        if (*(p + i) > largest)
            largest = *(p + i);
    }

    printf("Largest element = %d", largest);
}