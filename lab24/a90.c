//  Write a program to implement a Binary Search using Array. ( 
// recursive)
#include <stdio.h>
int binarySearch(int arr[], int start, int end, int key) {
    int mid = (start + end) / 2;
    if (start > end) {
        return -1; // Element not found
    }
    if(key>arr[mid]){
        start=mid+1;
        return binarySearch(arr, start, end, key);
    }
    else if(key<arr[mid]){
        end=mid-1;
        return binarySearch(arr, start, end, key);
    }
    else{
        return mid; // Element found
    }
}
void main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of array in sorted order: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at position %d\n", result + 1); // +1 for 1-based index
    }
}
