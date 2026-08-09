#include <stdio.h>

void main()
{
    int a[100], n, i;
    int num1, num2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number to replace: ");
    scanf("%d", &num1);

    printf("Enter new number: ");
    scanf("%d", &num2);

    for (i = 0; i < n; i++)
    {
        if (a[i] == num1)
        {
            a[i] = num2;
            printf("Replaced at index %d\n", i);
        }
    }

    printf("Final Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}