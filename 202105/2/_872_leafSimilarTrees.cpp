//
// Created by GYC on 2021/5/10.
//

#include "../../common.h"

class Solution {
private:
    void dfs(TreeNode *root, vector<int> &seq) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            seq.emplace_back(root->val);
        }
        if (root->left != nullptr) {
            dfs(root->left, seq);
        }
        if (root->right != nullptr) {
            dfs(root->right, seq);
        }
    }

public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> s1{}, s2{};
        dfs(root1, s1);
        dfs(root2, s2);
        return s1 == s2;
    }
};
