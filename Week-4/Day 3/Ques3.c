#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isInterleave(char*s1,char*s2,char*s3){
    int n=strlen(s1),m=strlen(s2);
    if(n+m!=strlen(s3))return false;
    
    bool**dp=(bool**)malloc((n+1)*sizeof(bool*));
    for(int i=0;i<=n;i++){
        dp[i]=(bool*)malloc((m+1)*sizeof(bool));
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0&&j==0)dp[i][j]=true;
            else if(i==0)dp[i][j]=(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
            else if(j==0)dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1]);
            else dp[i][j]=(dp[i-1][j]&&s1[i-1]==s3[i+j-1])||(dp[i][j-1]&&s2[j-1]==s3[i+j-1]);
        }
    }
    bool r=dp[n][m];
    for(int i=0;i<=n;i++)free(dp[i]);
    free(dp);
    return r;
}