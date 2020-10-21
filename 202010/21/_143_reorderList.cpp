//
// Created by gyc on 2020/10/20.
//

#include "../../common.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr|| head->next == nullptr) return;
        ListNode *f = head, *s = head;

        while (f->next != nullptr && f->next->next != nullptr) {
            f = f->next->next;
            s = s->next;
        }

        // 翻转后半部分链表
        ListNode *half = s->next, *next = half->next, *last = nullptr;
        while (next != nullptr) {
            half->next = last;
            last = half;
            half = next;
            next = half->next;
        }
        half->next = last;

        s->next = nullptr;
        ListNode *t1 = head, *t2 = half, *temp;
        while (t1 != nullptr) {
            temp = t1->next;
            t1->next = t2;
            t1 = temp;
            if (t2 != nullptr) {
                temp = t2->next;
                t2->next = t1;
                t2 = temp;
            }
        }
    }
};

int main() {
    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    Solution().reorderList(nullptr);

    cout << n1.val << endl;
}