#include <stdio.h>

void main()
{
    int start, end, i, j, prime;

    printf("Enter starting number: ");
    scanf("%d", &start);

    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for (i = start; i <= end; i++)
    {
        if (i <= 1)
            continue;

        prime = 1;

        for (j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }

        if (prime)
            printf("%d ", i);
    }
}