//
// Created by gyc on 2020/10/27.
//
#include "../../common.h"

class Solution {

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res{};
        if (nullptr == root) return res;

        stack<TreeNode*> ms{};

        ms.emplace(root);

        while (!ms.empty()) {

            TreeNode *t = ms.top();
            ms.pop();
            res.emplace_back(t->val);

            if (t->right != nullptr) {
                ms.emplace(t->right);
            }
            if (t->left != nullptr) {
                ms.emplace(t->left);
            }
        }
        return res;

    }
};