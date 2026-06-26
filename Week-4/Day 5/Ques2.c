#include<stdio.h>
#include<stdlib.h>
int uniquePathsWithObstacles(int**o,int oSz,int*oCol){
    int m=oSz,n=oCol[0];
    if(o[0][0]==1)return 0;

    long**dp=(long**)malloc(m*sizeof(long*));
    for(int i=0;i<m;i++){
        dp[i]=(long*)malloc(n*sizeof(long));
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(o[i][j]==1)dp[i][j]=0;
            else if(i==0&&j==0)dp[i][j]=1;
            else{
                long u=(i>0)?dp[i-1][j]:0;
                long l=(j>0)?dp[i][j-1]:0;
                dp[i][j]=u+l;
            }
        }
    }
    int r=(int)dp[m-1][n-1];
    for(int i=0;i<m;i++)free(dp[i]);
    free(dp);
    return r;
}