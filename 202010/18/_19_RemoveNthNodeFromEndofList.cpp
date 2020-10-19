//
// Created by uaniheng on 2020/10/18.
//
#include "../../common.h"

/**
 * Definition for singly-linked list.
 *
**/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr && n == 1) return nullptr;
        int step = n;
        ListNode *f = head, *s = head;
        while(f->next != nullptr) {
            f = f->next;
            if(step > 0) {
                --step;
            }else {
                s = s->next;
            }
        }
        if (step > 0) {
            return head->next;
        }else {
            s->next = s->next->next;
        }
        return head;
    }
};
