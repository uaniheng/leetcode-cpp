//
// Created by gyc on 2020/10/29.
//

#include "../../common.h"

class Solution {

public:
    int sumNumbers(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int sum = 0;
        queue<TreeNode*> nodeQ{};
        queue<int> numQ{};
        nodeQ.emplace(root);
        numQ.emplace(root->val);
        while (!nodeQ.empty()) {
            TreeNode *node = nodeQ.front();
            nodeQ.pop();
            int num = numQ.front();
            numQ.pop();
            TreeNode *left = node->left, *right = node->right;
            if (left == nullptr and right == nullptr) {
                sum += num;
            }else {
                if (left != nullptr) {
                    nodeQ.emplace(left);
                    numQ.emplace(num * 10 + left->val);
                }
                if (right != nullptr) {
                    nodeQ.emplace(right);
                    numQ.emplace(num * 10 + right->val);
                }
            }
        }
        return sum;
    }
};
