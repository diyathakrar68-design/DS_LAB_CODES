//  Write a program to implement a Linear Search using Array. 
#include<stdio.h>
int main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int key;
    printf("enter the element to be searched : ");
    scanf("%d",&key);
    int flag=0;
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            printf("element found at position %d\n",i+1);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("element not found\n");
    }           
    return 0;
}