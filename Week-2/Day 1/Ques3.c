#include<stdlib.h>
#ifndef LEETCODE_STRUCTS
struct TreeNode{
    int a;
    struct TreeNode*b;
    struct TreeNode*c;}
;
#endif
int*inorderTraversal(struct TreeNode*a,int*b){
    int*c=(int*)malloc(sizeof(int)*2000);
    struct TreeNode**d=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*2000);
    int e=0,f=0;
    struct TreeNode*g=a;
    while(g||e>0){
        if(g){
        d[e++]=g;
        g=g->b;
        }else{
            g=d[--e];
            c[f++]=g->a;
        g=g->c;
    }}
*b=f;
free(d);
return c;
}