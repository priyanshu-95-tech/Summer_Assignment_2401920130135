#include<stdio.h>
struct TreeNode{
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
};
struct TreeNode**solve(int s,int e,int*rSz){
    if(s>e){
        *rSz=1;
        struct TreeNode**r=(struct TreeNode**)malloc(sizeof(struct TreeNode*));
        r[0]=NULL;
        return r;
    }
    int t=0;
    struct TreeNode**r=(struct TreeNode**)malloc(sizeof(struct TreeNode*));
    for(int i=s;i<=e;i++){
        int lSz,rSz;
        struct TreeNode**l=solve(s,i-1,&lSz);
        struct TreeNode**rt=solve(i+1,e,&rSz);
        for(int j=0;j<lSz;j++){
            for(int k=0;k<rSz;k++){
                struct TreeNode*n=(struct TreeNode*)malloc(sizeof(struct TreeNode));
                n->val=i;
                n->left=l[j];
                n->right=rt[k];
                r=(struct TreeNode**)realloc(r,(t+1)*sizeof(struct TreeNode*));
                r[t++]=n;
            }
        }
    }
    *rSz=t;
    return r;
}

struct TreeNode**generateTrees(int n,int*rSz){
    if(n==0){
        *rSz=0;
        return NULL;
    }
    return solve(1,n,rSz);
}