#include <ctype.h>
#include <stdbool.h>
#include <string.h>
bool isPalindrome(char*s){
    int a= 0;
    int b=strlen(s) - 1;
    while (a<b){
        if (!isalnum(s[a])){
            a++;
        }else if (!isalnum(s[b])){
            b--;
        }else{
            if(tolower(s[a])!=tolower(s[b])){
                return false;
            }
            a++;
            b--;
        }}
    return true;
}