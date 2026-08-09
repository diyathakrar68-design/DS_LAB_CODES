#include <stdio.h>

void main()
{
    int a[100], n, i, pos, num;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter number: ");
    scanf("%d", &num);

    for (i = n; i >= pos; i--)
        a[i] = a[i - 1];

    a[pos - 1] = num;
    n++;

    printf("Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}