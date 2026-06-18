#include <stdio.h>
#include <stdlib.h>
void swap(int*a,int*b){
    int c=*a;
    *a=*b;
    *b=c;
}
void f(int*a,int b,int c,int**d,int*e){
    if(b==c){
        d[*e]=(int*)malloc((c+1)*sizeof(int));
        for(int i=0;i<=c;i++)d[*e][i]=a[i];
        (*e)++;
        return;
    }
    for(int i=b;i<=c;i++){
        swap(&a[b],&a[i]);
        f(a,b+1,c,d,e);
        swap(&a[b],&a[i]);
    }
}
int**permute(int*a,int b,int*c,int**d){
    int e=0;
    int f_n=1;
    for(int i=1;i<=b;i++)f_n*=i;
    int**g=(int**)malloc(f_n*sizeof(int*));
    *c=f_n;
    *d=(int*)malloc(f_n*sizeof(int));
    for(int i=0;i<f_n;i++)(*d)[i]=b;
    f(a,0,b-1,g,&e);
    return g;
}