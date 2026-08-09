#include <stdio.h>

void main()
{
    int a[100], n, i, num, pos = -1;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number to delete: ");
    scanf("%d", &num);

    for (i = 0; i < n; i++)
    {
        if (a[i] == num)
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (i = pos; i < n - 1; i++)
            a[i] = a[i + 1];
        n--;
    }

    printf("Updated Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}