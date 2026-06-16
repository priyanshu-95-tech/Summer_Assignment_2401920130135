#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void solve(char*a,int b,int c,char*d,int e,char**f,int*g){
    if(c==4){
        if(b==strlen(a)){
            f[(*g)++]=(char*)malloc(16*sizeof(char));
            strcpy(f[*g-1],d);
        }
        return;
    }
    for(int h=1;h<=3&&b+h<=strlen(a);h++){
        char i[4];
        strncpy(i,a+b,h);
        i[h]='\0';
        int j=atoi(i);
        if(j>255||(h>1&&i[0]=='0'))continue;
        int k=e;
        strcat(d,i);
        e+=h;
        if(c<3){
            strcat(d,".");
            e++;
        }
        solve(a,b+h,c+1,d,e,f,g);
        d[k]='\0';
        e=k;
    }
}
char**restoreIpAddresses(char*a,int*b){
    char**c=(char**)malloc(1000*sizeof(char*));
    char d[20]={'\0'};
    *b=0;
    solve(a,0,0,d,0,c,b);
    return c;
}