#include <stdio.h>

void main()
{
    int a[100], n, i, pos;

    printf("Enter size: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position: ");
    scanf("%d", &pos);

    for (i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    n--;

    printf("Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}