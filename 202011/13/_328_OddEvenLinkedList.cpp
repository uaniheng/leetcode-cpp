//
// Created by gyc on 2020/11/13.
//

#include "../../common.h"

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *h2 = head->next, *t1 = head, *t2 = h2;

        while (t1->next and t1->next->next) {
            t1->next = t1->next->next;
            t1 = t1->next;
            if (t2->next and t2->next->next) {
                t2->next = t2->next->next;
                t2 = t2->next;
            }
        }
        if (t2->next != nullptr){
            t2->next = nullptr;
        }
        t1->next = h2;
        return head;
    }
};