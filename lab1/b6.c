// WAP to convert seconds into HH:MM:SS.
#include <stdio.h>
void main()
{
    int seconds, hours, minutes, sec;

    printf("Enter total seconds: ");
    scanf("%d", &seconds);

    hours = seconds / 3600;
    minutes = (seconds % 3600) / 60;
    sec = seconds % 60;

    printf("Time = %d:%d:%d\n", hours, minutes, sec);
}