//
// Created by gyc on 2020/11/24.
//

#include "../../common.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q1{};
        q1.emplace(root);
        int count = 0;
        while (!q1.empty()) {
            ++count;
            auto n = q1.front();
            q1.pop();
            if (n->left != nullptr) q1.push(n->left);
            if (n->right != nullptr) q1.push(n->right);
        }
        return count;
    }
};