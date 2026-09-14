// Write a program to implement Merge Sort using Array.
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
    int i,j,k;
    for(i=1;i<n;i=i*2){
        for(j=0;j<n;j=j+2*i){
            int left=j;
            int mid=j+i-1;
            int right=j+2*i-1;
            if(mid>=n){
                mid=n-1;
            }
            if(right>=n){
                right=n-1;
            }
            int temp[right-left+1];
            k=0;
            int p=left,q=mid+1;
            while(p<=mid && q<=right){
                if(arr[p]<=arr[q]){
                    temp[k++]=arr[p++];
                }
                else{
                    temp[k++]=arr[q++];
                }
            }
            while(p<=mid){
                temp[k++]=arr[p++];
            }
            while(q<=right){
                temp[k++]=arr[q++];
            }
            for(k=0;k<right-left+1;k++){
                arr[left+k]=temp[k];
            }
        }
    }
    printf("the sorted array is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}