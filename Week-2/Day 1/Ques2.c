#include<stdlib.h>
#include<string.h>
void g(char*a,int b,int c,int d,char**e,int*f){
    if(strlen(a)==2*d){
        e[*f]=(char*)malloc(sizeof(char)*(2*d+1));
        strcpy(e[*f],a);
        (*f)++;
        return;}
    if(b<d){
        int h=strlen(a);
        a[h]='(';
        a[h+1]='\0';
        g(a,b+1,c,d,e,f);
        a[h]='\0';
    }if(c<b){
        int i=strlen(a);
        a[i]=')';
        a[i+1]='\0';
        g(a,b,c+1,d,e,f);
        a[i]='\0';
    }
}
char** generateParenthesis(int a,int*b){
    char**c=(char**)malloc(sizeof(char*)*1430);
    char*d=(char*)malloc(sizeof(char)*(2*a+1));
    d[0]='\0';
    int e=0;
    g(d,0,0,a,c,&e);
    *b=e;
    return c;}