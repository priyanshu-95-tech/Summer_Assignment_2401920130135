#include <stdlib.h>
#include <string.h>
char* a(char d) {
    if (d=='2') return "abc";
    if (d=='3') return "def";
    if (d=='4') return "ghi";
    if (d=='5') return "jkl";
    if (d=='6') return "mno";
    if (d=='7') return "pqrs";
    if (d=='8') return "tuv";
    if (d=='9') return "wxyz";
    return "";}
void b(char* digits,int c,char* d,char** e,int* f) {
    if (digits[c]=='\0') {
        e[*f]=strdup(d);
        (*f)++;
        return;
    }
    char* g=a(digits[c]);
    for (int h=0;g[h]!='\0';h++) {
        d[c]=g[h];
        b(digits,c+1,d,e,f);
    }}
char** letterCombinations(char* digits, int* returnSize) {
    if (digits[0]=='\0') {
        *returnSize=0;
        return NULL;}
    int i=1;
    for (int j=0; digits[j]!='\0';j++) {
        i *= strlen(a(digits[j]));}
    char** e= (char**)malloc(i*sizeof(char*));
    char* d=(char*)malloc((strlen(digits) + 1) * sizeof(char));
    d[strlen(digits)] = '\0';
    *returnSize = 0;
    b(digits,0,d,e,returnSize);
    return e;
}