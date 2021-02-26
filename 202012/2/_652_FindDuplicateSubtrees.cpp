//
// Created by gyc on 2020/12/9.
//
#include "../../common.h"

class Solution {

private:

    unordered_map<string, int> count{};
    vector<TreeNode*> ans{};

    string collect(TreeNode *node) {
        if (node == nullptr) return "#";
        string serial = to_string(node->val) + "," + collect(node->left) + "," + collect(node->right);
        count[serial] = (count.count(serial) ? count[serial]:0) + 1;
        if (count[serial] == 2)
            ans.emplace_back(node);
        return serial;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        collect(root);
        return ans;
    }
};

