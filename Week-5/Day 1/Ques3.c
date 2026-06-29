#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void* a,const void* b){
    char sa[40];
    char sb[40];
    char combination1[80];
    char combination2[80];
    sprintf(sa,"%d",*(int*)a);
    sprintf(sb,"%d",*(int*)b);
    strcpy(combination1,sa);
    strcat(combination1,sb);
    strcpy(combination2,sb);
    strcat(combination2,sa);
    return strcmp(combination2,combination1);
}
char* largestNumber(int* nums,int numsSize){
    qsort(nums,numsSize,sizeof(int),compare);
    if(nums[0]==0){
        char* zero=malloc(2*sizeof(char));
        strcpy(zero,"0");
        return zero;
    }
    int total_len=0;
    for(int i=0;i<numsSize;i++){
        char temp[40];
        sprintf(temp,"%d",nums[i]);
        total_len+=strlen(temp);
    }
    char* result=malloc((total_len+1)*sizeof(char));
    result[0]='\0';
    for(int i=0;i<numsSize;i++){
        char temp[40];
        sprintf(temp,"%d",nums[i]);
        strcat(result,temp);
    }
    return result;
}