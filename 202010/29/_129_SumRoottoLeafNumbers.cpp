//
// Created by gyc on 2020/10/29.
//

#include "../../common.h"

class Solution {

private:

    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return sum;
        sum = sum * 10 + root->val;
        if (root->left == nullptr and root->right == nullptr) {
            return sum;
        }
        int res = 0;
        if (root->left != nullptr) {
            res += dfs(root->left, sum);
        }
        if (root->right != nullptr) {
            res += dfs(root->right, sum);
        }
        return res;
    }


public:
    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};
