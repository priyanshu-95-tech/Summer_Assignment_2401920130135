#include<stdio.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";
    char* base = strs[0];
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (base[j] !='\0' && strs[i][j]!= '\0'&& base[j]==strs[i][j]){
            j++;
        }
        base[j] = '\0';
        if (base[0]=='\0') break;
    }
    return base;
}