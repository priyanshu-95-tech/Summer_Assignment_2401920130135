#include<stdbool.h>
int compare(const void*a,const void*b){
    return(*(int*)a-*(int*)b);
}

bool containsDuplicate(int*nums,int n){
    qsort(nums,n,sizeof(int),compare);
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]){
            return true;
        }
    }
    return false;
}