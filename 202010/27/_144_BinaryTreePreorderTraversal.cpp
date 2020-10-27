//
// Created by gyc on 2020/10/27.
//
#include "../../common.h"

class Solution {

private:
    vector<int> res{};

    void recursion(TreeNode *root) {

        if (root == nullptr) return;
        res.emplace_back(root->val);
        recursion(root->left);
        recursion(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {

        recursion(root);
        return res;
    }
};