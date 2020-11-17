//
// Created by gyc on 2020/11/17.
//
#include "../../common.h"

class Solution {
private:
    TreeNode *build(vector<int> &nums, int begin, int end) {
        if (begin >= end) {
            return nullptr;
        } else {
            auto max = max_element(nums.begin() + begin, nums.begin() + end);
            int index = max - nums.begin();
            auto node = new TreeNode(*max);
            node->left = build(nums, begin, index);
            node->right = build(nums, index + 1, end);
            return node;
        }
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return build(nums, 0, nums.size());
    }
};

int main() {

    vector<int> vec{3, 2, 1, 6, 0, 5};
    auto res = Solution().constructMaximumBinaryTree(vec);


    cout << res->val << endl;

    vector<int> v{1, 2, 3, 4};

    cout << true << endl;

}