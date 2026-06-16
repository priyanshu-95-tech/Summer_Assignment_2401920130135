#include <stdio.h>
#include <limits.h>
int myAtoi(char*a){
    int b=0,c=1,i=0;
    while(a[i]==' ')i++;
    if(a[i]=='-'||a[i]=='+'){
        c=(a[i++]=='-')?-1:1;
    }
    while(a[i]>='0'&&a[i]<='9'){
        int d=a[i++]-'0';
        if(b>INT_MAX/10||(b==INT_MAX/10&&d>INT_MAX%10)){
            return (c==1)?INT_MAX:INT_MIN;
        }
        b=b*10+d;
    }
    return b*c;
}