#include <stdio.h>
void swap(int*a,int*b){
    int c=*a;
    *a=*b;
    *b=c;
}
void nextPermutation(int*a,int b){
    int c=b-2;
    while(c>=0&&a[c]>=a[c+1])c--;
    if(c>=0){
        int d=b-1;
        while(a[d]<=a[c])d--;
        swap(&a[c],&a[d]);
    }
    int e=c+1,f=b-1;
    while(e<f){
        swap(&a[e++],&a[f--]);
    }
}