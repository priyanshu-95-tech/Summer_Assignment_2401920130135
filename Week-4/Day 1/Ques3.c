#include<stdbool.h>
bool canJump(int*n,int nSz){
    int m=0;
    for(int i=0;i<nSz;i++){
        if(i>m)return false;
        int r=i+n[i];
        if(r>m)m=r;
        if(m>=nSz-1)return true;
    }
    return false;
}