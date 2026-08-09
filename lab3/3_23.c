#include <stdio.h>
#include <string.h>

void main()
{
    char name[20][30], temp[30];
    int n, i, j;

    printf("Enter number of names: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for (i = 0; i < n; i++)
        scanf("%s", name[i]);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    printf("Names in alphabetical order:\n");

    for (i = 0; i < n; i++)
        printf("%s\n", name[i]);
}