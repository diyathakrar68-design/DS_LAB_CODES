#include <stdio.h>

void main()
{
    int a[50], b[50], c[100];
    int n1, n2, i;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter first array:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter second array:\n");
    for (i = 0; i < n2; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < n1; i++)
        c[i] = a[i];

    for (i = 0; i < n2; i++)
        c[n1 + i] = b[i];

    printf("Merged Array:\n");

    for (i = 0; i < n1 + n2; i++)
        printf("%d ", c[i]);
}