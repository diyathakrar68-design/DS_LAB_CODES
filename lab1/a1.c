// WAP to calculate area of a Circle (A = πr2).
#include<stdio.h>
void main(){
    int radius;
    printf("enter the radius of the circle : ");
    scanf("%d",&radius);
    int area = (3.14 * radius* radius);
    printf("%d",area);
}