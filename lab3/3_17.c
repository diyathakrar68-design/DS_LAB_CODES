#include<stdio.h>
void main(){
    int m;
    int n;
    int i;
    int sum=0;
    printf("enter the value of m and n : ");
    scanf("%d %d",&m,&n);
    int size=n-m+1;
    int a[size];
    for(i=0;i<size;i++){
        a[i]=m+i;
        
    }
    for(i=0;i<size;i++){
        sum+=a[i];
    }
   
    printf("the summation of terms is %d ",sum);
}