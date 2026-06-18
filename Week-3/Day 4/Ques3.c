#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
bool isSameTree(struct TreeNode* a,struct TreeNode* b) {
    if(!a&&!b)return true;
    if(!a||!b||a->val!=b->val)return false;
    return isSameTree(a->left,b->left)&&isSameTree(a->right,b->right);
}
int main() {
    struct TreeNode* a=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    a->val=1;
    a->left=NULL;
    a->right=NULL;
    struct TreeNode* b=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    b->val=1;
    b->left=NULL;
    b->right=NULL;
    if(isSameTree(a,b)) {
        printf("Trees are identical!\n");
    } else {
        printf("Trees are different!\n");
    }
    return 0;
}