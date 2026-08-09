// WAP to convert days into years, weeks, and days.
#include <stdio.h>
void main()
{
    int totalDays, years, weeks, days;

    printf("Enter number of days: ");
    scanf("%d", &totalDays);

    years = totalDays / 365;
    weeks = (totalDays % 365) / 7;
    days = (totalDays % 365) % 7;

    printf("%d days = %d Year, %d Week, %d Day\n", totalDays, years, weeks, days);
}