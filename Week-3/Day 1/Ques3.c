#include <stdlib.h>
int*searchRange(int*a,int n,int t,int*rS){
    *rS=2;
    int*r=(int*)malloc(2*sizeof(int));
    r[0]=-1;r[1]=-1;
    if(n==0)return r;
    int l=0,h=n-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(a[m]>=t)h=m-1;
        else l=m+1;
    }
    if(l<n&&a[l]==t)r[0]=l;
    else return r;
    h=n-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(a[m]<=t)l=m+1;
        else h=m-1;
    }
    r[1]=h;
    return r;
}