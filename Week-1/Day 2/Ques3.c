#include<stdio.h>
#include<stdlib.h>
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry =1;
    int i =digitsSize -1;
    while (i >=0 &&carry) {
        int sum =digits[i] + carry;
        digits[i] = sum %10;
        carry= sum /10;
        i--;
    }
    if (carry){
        *returnSize=digitsSize + 1;
        int* result=(int*)malloc((*returnSize) * sizeof(int));
        result[0]=1;
        for (int k =1;k <*returnSize;k++) {
            result[k] =0;
        }
        return result;
    } else {
        *returnSize =digitsSize;
        return digits;
    }
}