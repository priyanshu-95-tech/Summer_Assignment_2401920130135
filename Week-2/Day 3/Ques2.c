#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* swapPairs(struct ListNode* head) {
    if (head==NULL||head->next==NULL) return head;
    struct ListNode a;
    a.next=head;
    struct ListNode* b=&a;
    while (b->next!=NULL&&b->next->next!=NULL) {
        struct ListNode* c=b->next;
        struct ListNode* d=b->next->next;
        c->next=d->next;
        d->next=c;
        b->next=d;
        b=c;
    }
    return a.next;}