#include <stdio.h>

void main()
{
    int a[100], n, i, j;
    int duplicate = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 1)
        {
            break;
        }
    }

    if (duplicate == 1)
    {
        printf("Duplicate number found.");
    }
    else
    {
        printf("No duplicate number found.");
    }
}