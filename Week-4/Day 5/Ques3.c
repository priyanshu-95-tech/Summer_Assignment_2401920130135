#include<stdio.h>
char*simplifyPath(char*p){
    int n=strlen(p);
    char**s=(char**)malloc(n*sizeof(char*));
    int t=0;
    char*tkn=strtok(p,"/");
    while(tkn){
        if(strcmp(tkn,"..")==0){
            if(t>0)t--;
        }else if(strcmp(tkn,".")!=0){
            s[t++]=tkn;
        }
        tkn=strtok(NULL,"/");
    }
    char*r=(char*)malloc((n+1)*sizeof(char));
    r[0]='\0';
    for(int i=0;i<t;i++){
        strcat(r,"/");
        strcat(r,s[i]);
    }
    if(t==0)strcat(r,"/");
    free(s);
    return r;
}