#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*convert(char*a,int b){
    int c=strlen(a);
    if(b==1||b>=c)return a;
    char*r=(char*)malloc((c+1)*sizeof(char));
    int k=0,d=2*(b-1);
    for(int i=0;i<b;i++){
        for(int j=i;j<c;j+=d){
            r[k++]=a[j];
            if(i>0&&i<b-1&&j+d-2*i<c)
                r[k++]=a[j+d-2*i];
        }
    }
    r[k]='\0';
    return r;
}