//
// Created by gyc on 2020/12/23.
//
#include "../../common.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root== nullptr) return vector<vector<int>>{};
        vector<vector<int>> result{};
        queue<TreeNode*> mq{};
        mq.emplace(root);
        int tag = 1;
        while (!mq.empty()) {
            int size = mq.size();
            auto *v1 = new vector<int>();
            v1->reserve(size);
            for (int i = 0; i < size; ++i) {
                v1->emplace_back(mq.front()->val);
                if (mq.front()->left != nullptr) {
                    mq.emplace(mq.front()->left);
                }
                if (mq.front()->right != nullptr) {
                    mq.emplace(mq.front()->right);
                }
                mq.pop();
            }
            if (tag == -1) {
                reverse(v1->begin(), v1->end());
            }
            result.emplace_back(*v1);
            tag *= -1;
        }
        return result;
    }
};

int main() {


}