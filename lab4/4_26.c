#include <stdio.h>

void main()
{
    int a[100], n, i, num;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter number: ");
    scanf("%d", &num);

    for (i = n - 1; i >= 0 && a[i] > num; i--)
        a[i + 1] = a[i];

    a[i + 1] = num;
    n++;

    printf("Updated Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}