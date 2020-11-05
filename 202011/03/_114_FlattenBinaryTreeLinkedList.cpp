//
// Created by gyc on 2020/11/4.
//

#include "../../common.h"

class Solution {

private:

    TreeNode *myFlatten(TreeNode *root) {
        if (root == nullptr) return nullptr;
        if (root->left == nullptr && root->right == nullptr) {
            return root;
        }
        if (root->left == nullptr) {
            return myFlatten(root->right);
        }
        TreeNode *t1 = root->right;
        root->right = root->left;
        root->left = nullptr;
        TreeNode *t2 = myFlatten(root->right);
        if (t1 == nullptr) {
            return t2;
        }
        t2->right = t1;
        return myFlatten(t1);
    }

public:
    void flatten(TreeNode *root) {
        myFlatten(root);
    }
};