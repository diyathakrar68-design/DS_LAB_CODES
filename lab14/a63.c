// Given a set of time intervals in any order, our task is to merge all overlapping 
// intervals into one and output the result which should have only mutually 
// exclusive intervals.

#include <stdio.h>
struct Interval {
    int start;
    int end;
};
void mergeIntervals(struct Interval arr[], int n) {
    // Sort intervals based on start time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].start > arr[j + 1].start) {
                struct Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    struct Interval merged[n];
    int index = 0;

    merged[index] = arr[0];

    for (int i = 1; i < n; i++) {
        if (merged[index].end >= arr[i].start) {
            merged[index].end = (merged[index].end > arr[i].end) ? merged[index].end : arr[i].end;
        } else {
            index++;
            merged[index] = arr[i];
        }
    }

    printf("Merged Intervals:\n");
    for (int i = 0; i <= index; i++) {
        printf("[%d, %d]\n", merged[i].start, merged[i].end);
    }
}
int main() {
    struct Interval arr[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}