// Write a program to implement Selection Sort using Array. 
#include<stdio.h>
void main(){
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array : ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    printf("the sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}