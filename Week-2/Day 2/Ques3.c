#include <stdio.h>
#include <stdlib.h>
struct ListNode{
    int val;
    struct ListNode *next;
};
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head||!head->next||k==0) return head;
    struct ListNode* a=head;
    int b=1;
    while (a->next){
        a=a->next;
        b++;
    }
    a->next=head;
    k=k% b;
    int c= b-k;
    while (c--){
        a=a->next;
    }
    head=a->next;
    a->next= NULL;
    return head;}