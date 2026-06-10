#include <string.h>
int lengthOfLongestSubstring(char* s) {
    int a[256];
    int b=0,c=0;
    for(int i=0;i<256;i++){
        a[i]=-1;
    }
    for(int i=0;s[i]!='\0';i++){
        if(a[(unsigned char)s[i]]>=b){
            b=a[(unsigned char)s[i]]+1;
        }
        a[(unsigned char)s[i]]=i;

        if(i-b+1>c){
            c=i-b+1;
        }
    }
    return c;
}