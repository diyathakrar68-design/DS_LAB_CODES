// Write a program to implement Quick Sort using Array. 
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
    int i,j,pivot,temp;
    for(i=0;i<n-1;i++){
        pivot=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[pivot]){
                pivot=j;
            }
        }
        if(pivot!=i){
            temp=arr[i];
            arr[i]=arr[pivot];
            arr[pivot]=temp;
        }
    }
    printf("the sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}