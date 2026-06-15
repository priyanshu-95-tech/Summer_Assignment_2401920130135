#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char*countAndSay(int n){
    char*s=(char*)malloc(5000*sizeof(char));
    strcpy(s,"1");
    for(int i=1;i<n;i++){
        char*t=(char*)malloc(5000*sizeof(char));
        int k=0;
        int l=strlen(s);
        for(int j=0;j<l;j++){
            int c=1;
            while(j+1<l&&s[j]==s[j+1]){
                c++;
                j++;
            }
            k+=sprintf(t+k,"%d%c",c,s[j]);
        }
        t[k]='\0';
        free(s);
        s=t;
    }
    return s;
}