//
// Created by gyc on 2020/9/29.
//
#include "../../common.h"

class Solution {

private:
    unordered_map<TreeNode*, int> note{};

public:
    int rob(TreeNode *root) {

        if (root == nullptr) return 0;
        if (note.count(root)) return note[root];
        int curr = root->val
                + (root->left == nullptr ? 0:rob(root->left->left) + rob(root->left->right))
                + (root->right == nullptr ? 0:rob(root->right->left) + rob(root->right->right));
        int next = rob(root->left) + rob(root->right);

        int res = max(curr, next);
        note[root] = res;
        return res;
    }
};

int main() {


}