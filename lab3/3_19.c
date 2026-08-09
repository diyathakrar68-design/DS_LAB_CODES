#include <stdio.h>

void main()
{
    int a[100], n, i;
    int small, large;
    int sPos = 0, lPos = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    small = a[0];
    large = a[0];

    for (i = 1; i < n; i++)
    {
        if (a[i] < small)
        {
            small = a[i];
            sPos = i;
        }

        if (a[i] > large)
        {
            large = a[i];
            lPos = i;
        }
    }

    printf("Smallest number = %d\n", small);
    printf("Position = %d\n", sPos + 1);

    printf("Largest number = %d\n", large);
    printf("Position = %d\n", lPos + 1);
}