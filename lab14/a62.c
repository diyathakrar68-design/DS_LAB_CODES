// You are given a string s, which contains stars *. In one operation, you can: 
// Choose a star in s. Remove the closest non-star character to its left, as well as 
// remove the star itself. Return the string after all stars have been removed. 

#include <stdio.h>
#include <string.h>

int main()
{
    char s[1000];
    int i, j = 0;

    printf("Enter a string: ");
    scanf("%s", s);

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '*')
        {
            j--;
        }
        else
        {
            s[j++] = s[i];
        }
    }

    s[j] = '\0';

    printf("Result: %s\n", s);

    return 0;
}
