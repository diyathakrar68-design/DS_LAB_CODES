#include<stdio.h>
void main(){
    int a[10];
    int i;
    for(i=0;i<10;i++){
        printf("enter the number :");
        scanf("%d",&a[i]);
    }
    for(i=0;i<=10;i++){
        printf("%d ",a[i]); 
        
    }
}