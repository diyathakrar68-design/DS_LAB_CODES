#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
    int n, i, j;
    int flag = 0;
    printf("enter the size :");
    scanf("%d", &n);
    char arr[n][50];
    for (i = 0; i < n; i++)
    {
        printf("enter the array element : ");
        scanf("%s", arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%s", arr[i]);
    }
    int index = rand() % n;
    char original[50];
    int visited[50]={0};
    strcpy(original, arr[index]);
    int original_size = strlen(original);
    char user[50];
    printf("Enter a word: ");
    scanf("%s", user);

    int user_size = strlen(user);

    printf("%s\n", user);
    if (original_size == user_size)
    {
        for (i = 0; i < original_size; i++)
        {
            for (j = 0; j < user_size; j++)
            {
                if (original[i] == user[j] && visited[j] == 0)
                {
                    visited[j] = 1;
                    flag++;
                    break;
                }
            }
        }
        if (flag == original_size)
        {
            printf("this string is anagram ");
        }
        else
        {
            printf("this string is not anagram ");
        }
    }
}
