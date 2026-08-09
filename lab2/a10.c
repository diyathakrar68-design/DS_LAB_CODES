// WAP to reverse a number
#include <stdio.h>
void main()
{
    int n;
    printf("enter the number : ");
    scanf("%d", &n);
    int ans;
    int f_ans = 0;
    while (n != 0)
    {
        ans = n % 10;
        n = n / 10;
        f_ans = (f_ans * 10) + ans;
    }
    printf("the reverse number is %d", f_ans);
}