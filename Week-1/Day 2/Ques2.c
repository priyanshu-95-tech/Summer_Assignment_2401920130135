#include<stdio.h>
int searchInsert(int* nums, int numsSize, int target) {
    int a = 0;
    int b = numsSize;
    while (a < b) {
        int mid = a + (b- a)/2;
        if (nums[mid]< target) {
            a= mid+1;
        }
        else{
            b = mid;
        }
    }
    return a;
}