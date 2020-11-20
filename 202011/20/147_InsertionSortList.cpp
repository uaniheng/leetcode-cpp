//
// Created by gyc on 2020/11/20.
//

#include "../../common.h"

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {

        auto *h = new ListNode(0), *curr = head, *last = h, *temp = curr;
        h->next = head;

        while (curr != nullptr) {
            temp = curr;
            curr = curr->next;
            last->next = curr;

            ListNode *pre = h;
            while (pre->next != curr && temp->val > pre->next->val) {
                pre = pre->next;
            }
            temp->next = pre->next;
            pre->next = temp;
            if (last == pre) {
                last = temp;
            }
        }
        return h->next;
    }
};

int main() {

    auto a = new ListNode(4), b = new ListNode(2), c = new ListNode(1), d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;

    auto res = Solution().insertionSortList(a);

    while (res != nullptr) {
        cout << res->val << endl;
        res = res->next;
    }
}