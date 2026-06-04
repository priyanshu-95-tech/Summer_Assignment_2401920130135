#include<stdio.h>
#ifndef LIST_H
#define LIST_H

struct ListNode {
    int val;
    struct ListNode *next;
};

#endif

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return NULL;
    struct ListNode* current = head;
    while (current->next) {
        if (current->val== current->next->val) {
            struct ListNode* temp= current->next;
            current->next =current->next->next;
        } else {
            current = current->next;
        }
    }
    return head;
}