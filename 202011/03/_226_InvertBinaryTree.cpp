//
// Created by gyc on 2020/11/4.
//
#include "../../common.h"

class Solution {

private:

    void invert(TreeNode* root) {
        if (root == nullptr) return;
        auto temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
