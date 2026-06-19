#include<stdbool.h>
bool isValidSudoku(char**b,int rS,int*cSz){
    int r[9][9]={0},c[9][9]={0},s[9][9]={0};
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(b[i][j]!='.'){
                int v=b[i][j]-'1';
                int k=(i/3)*3+(j/3);
                if(r[i][v]||c[j][v]||s[k][v]){
                    return false;
                }
                r[i][v]=1;
                c[j][v]=1;
                s[k][v]=1;
            }
        }
    }
    return true;
}