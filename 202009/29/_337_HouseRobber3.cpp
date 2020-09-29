//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {

private:
    int *dp(TreeNode *root) {
        if (root == nullptr) return new int[]{0, 0};
        int *left = dp(root->left);
        int *right = dp(root->right);
        int curr = root->val + left[1] + right[1];
        int next = max(left[0], left[1]) + max(right[0], right[1]);
        delete [] left;
        delete [] right;
        return new int[]{curr, next};
    }

public:
    int rob(TreeNode *root) {
        int* res = dp(root);
        return max(res[0], res[1]);
    }
};

int main() {


}