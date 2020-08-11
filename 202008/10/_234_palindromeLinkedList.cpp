//
// Created by gyc on 2020/8/6.
//
#define NULL nullptr

#include <stack>
#include <vector>
#include <iostream>

using namespace std;
/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {

private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr != nullptr) {
            ListNode *nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode *endOfFirstHalf(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    bool isPalindrome(ListNode *head) {
        if (head == nullptr) return true;
        // 后半段链表头
        ListNode *firstHalfEnd = endOfFirstHalf(head);
        // 翻转链表
        ListNode *secondHalfStart = reverseList(firstHalfEnd->next);
        // 判断是否是回文串
        ListNode *t1 = head, *t2 = secondHalfStart;
        bool r = true;
        while (r && t2 != nullptr) {
            if (t1->val != t2->val) r = false;
            t1 = t1->next;
            t2 = t2->next;
        }
        reverseList(secondHalfStart);
        return true;
    }
};

/**
 * 第二天重复做
 */
class Solution1 {

private:
    ListNode *findMiddle(ListNode *head) {
        if (head == nullptr) return head;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head) {
        ListNode *pre = nullptr, *curr = head, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }

public:
    bool isPalindrome (ListNode *head) {
        if (head == nullptr) return true;
        //find middle
        ListNode *mid = findMiddle(head);
        // reverse second part
        ListNode *secondPart = reverse(mid->next);
        // judge
        ListNode *p1 = head, *p2 = secondPart;
        bool r = true;
        while (r && p2) {
            if (p1->val != p2->val) r = false;
            p1 = p1->next;
            p2 = p2->next;
        }
        // reverse
        reverse(secondPart);
        // return
        return r;
    }
};

int main () {
    auto n1 = new ListNode(2);
    auto n2 = new ListNode(3);
    auto n3 = new ListNode(4);
    auto n4 = new ListNode(4);
    auto n5 = new ListNode(3);
    auto n6 = new ListNode(2);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << (new Solution1)->isPalindrome(nullptr) << endl;
}