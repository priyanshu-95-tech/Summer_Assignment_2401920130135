
#include<stdio.h>
int cmp(const void*a,const void*b){return(*(int*)a-*(int*)b);}
void solve(int*c,int cSz,int t,int s,int*tmp,int tSz,int***r,int*rSz,int**cSzs){
    if(t==0){
        int*a=(int*)malloc(tSz*sizeof(int));
        for(int i=0;i<tSz;i++)a[i]=tmp[i];
        *r=(int**)realloc(*r,(*rSz+1)*sizeof(int*));
        (*r)[*rSz]=a;
        *cSzs=(int*)realloc(*cSzs,(*rSz+1)*sizeof(int));
        (*cSzs)[*rSz]=tSz;
        (*rSz)++;
        return;
    }
    for(int i=s;i<cSz;i++){
        if(i>s&&c[i]==c[i-1])continue;
        if(c[i]<=t){
            tmp[tSz]=c[i];
            solve(c,cSz,t-c[i],i+1,tmp,tSz+1,r,rSz,cSzs);
        }
    }
}
int**combinationSum2(int*c,int cSz,int t,int*rSz,int**cSzs){
    qsort(c,cSz,sizeof(int),cmp);
    int**r=NULL;
    *rSz=0;
    *cSzs=NULL;
    int*tmp=(int*)malloc(1000*sizeof(int));
    solve(c,cSz,t,0,tmp,0,&r,rSz,cSzs);
    free(tmp);
    return r;
}