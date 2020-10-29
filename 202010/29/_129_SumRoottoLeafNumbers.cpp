//
// Created by gyc on 2020/10/29.
//

#include "../../common.h"

class Solution {

private:

    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) return 0;
        sum = sum * 10 + root->val;
        if (root->left == nullptr and root->right == nullptr) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }


public:
    int sumNumbers(TreeNode* root) {

        return dfs(root, 0);
    }
};
