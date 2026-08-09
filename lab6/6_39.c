#include <stdio.h>
#include <string.h>

void main()
{
    char str[100];
    char *start, *end;
    int flag = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    start = str;
    end = str + strlen(str) - 1;

    while (start < end)
    {
        if (*start != *end)
        {
            flag = 0;
            break;
        }
        start++;
        end--;
    }

    if (flag)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}