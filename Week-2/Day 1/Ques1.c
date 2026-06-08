#include<stdlib.h>
struct ListNode{
    int a;
    struct ListNode*b;
};
struct ListNode*removeNthFromEnd(struct ListNode*c,int d){
    struct ListNode*e=(struct ListNode*)malloc(sizeof(struct ListNode));
    e->b=c;
    struct ListNode*f=e;
    struct ListNode*g=e;
    for(int h=0;h<=d;h++)
    {f=f->b;
    }
    while(f!=NULL){
        f=f->b;
        g=g->b;
    }
    struct ListNode*i=g->b;
    g->b=g->b->b;
    free(i);
    struct ListNode*j=e->b;
    free(e);
    return j;
}