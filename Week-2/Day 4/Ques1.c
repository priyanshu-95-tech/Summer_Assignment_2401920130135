#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode*next;
};
struct ListNode*insertionSortList(struct ListNode*head){
    if(!head)return head;
    struct ListNode*d=(struct ListNode*)malloc(sizeof(struct ListNode));
    d->next=head;
    struct ListNode*curr=head->next;
    head->next=NULL;
    while(curr){
        struct ListNode*p=d;
        while(p->next&&p->next->val<curr->val){
            p=p->next;
        }struct ListNode*t=curr->next;
        curr->next=p->next;
        p->next=curr;
        curr=t;
    }
    struct ListNode*res=d->next;
    free(d);
    return res;
}