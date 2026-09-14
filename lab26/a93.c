// Write a program to implement Insertion Sort using Array.
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
    int key ,i,j;
    i=1;
    while(i<n){
        key=arr[i];
        j=i-1;
        if(j!=1){
            while(j>=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
        }
        arr[j+1]=key;
        i++;
    }
    printf("the sorted array is : ");
    for(int i=0;i<n;i++){           
        printf("%d ",arr[i]);
    }
    printf("\n");
}