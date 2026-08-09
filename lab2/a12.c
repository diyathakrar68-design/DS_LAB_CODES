// WAP to check whether a number is prime or not
#include<stdio.h>
void main(){
    int n ,i;
    printf("enter the number : ");
    scanf("%d",&n);
    int flag=0;
    for(i=2;i<n;i++){
        if(n%i==0){
            flag++;
        }
    } 
    if(flag==0){
        printf("the number is prime :");
    }
    else{
        printf("the number is not prime :");
    }
}