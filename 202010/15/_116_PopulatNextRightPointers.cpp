//
// Created by gyc on 2020/10/15.
//
#include "../../common.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) return root;

        queue<Node *> nq{};

        nq.push(root);
        while (!nq.empty()) {
            Node *last = nullptr;
            int n = nq.size();
            for (int i = 0; i < n; ++i) {
                Node *curr = nq.front();
                if (curr->left != nullptr) nq.push(curr->left);
                if (curr->right!= nullptr) nq.push(curr->right);
                nq.pop();
                if (last != nullptr) {
                    last->next = curr;
                }
                last = curr;
            }
        }
        return root;
    }
};
