#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*multiply(char*a,char*b){
    int c=strlen(a),d=strlen(b);
    if(a[0]=='0'||b[0]=='0')return strdup("0");
    int*e=(int*)calloc(c+d,sizeof(int));
    for(int i=c-1;i>=0;i--){
        for(int j=d-1;j>=0;j--){
            int f=(a[i]-'0')*(b[j]-'0');
            int g=i+j,h=i+j+1;
            int i_s=f+e[h];
            e[h]=i_s%10;
            e[g]+=i_s/10;
        }
    }
    char*r=(char*)malloc((c+d+1)*sizeof(char));
    int k=0,l=0;
    while(l<c+d&&e[l]==0)l++;
    while(l<c+d)r[k++]=e[l++]+'0';
    r[k]='\0';
    free(e);
    return r;
}