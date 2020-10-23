//
// Created by gyc on 2020/10/23.
//

#include "../../common.h"


// Definition for singly-linked list.


class Solution {
public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
        // half
        ListNode *f = head, *s = head;
        while (f->next != nullptr && f->next->next != nullptr) {
            f = f->next->next;
            s = s->next;
        }
        ListNode *half;
        if (s->next != nullptr) {
            half = s->next;
        }else {
            half = s;
        }

        ListNode *last = nullptr, *next = half->next;
        while (next != nullptr) {
            half->next = last;
            last = half;
            half = next;
            next = half->next;
        }
        half->next = last;
        ListNode *t1 = head, *t2 = half;
        while (t2 != nullptr) {
            if (t1->val != t2->val) {
                return false;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
        return true;
    }
};

int main() {
    ListNode n1(1), n2(1), n3(2), n4(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    cout << Solution().isPalindrome(&n1);
}