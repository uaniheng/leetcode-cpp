//
// Created by gyc on 2020/11/18.
//

#include "../../common.h"

class Solution {

private:
    vector<int> *preorder , *inorder;

    TreeNode *build(int preBegin, int inBegin, int size) {

        if (preBegin >= preorder->size() || inBegin >= inorder->size() || size < 1) {
            return nullptr;
        }
        int rootVal = (*preorder)[preBegin];
        auto *root = new TreeNode(rootVal);
        int lSize = 0;
        while ((*preorder)[preBegin] != (*inorder)[inBegin]) {
            ++inBegin;
            ++lSize;
        }
        root->left = build(preBegin + 1, inBegin - lSize, lSize);
        root->right = build(preBegin + lSize + 1, inBegin + 1, size - lSize - 1);
        return root;
    }


public:
    TreeNode *buildTree(vector<int> &preorder1, vector<int> &inorder1) {
        this->preorder = &preorder1;
        this->inorder = &inorder1;
        return build(0, 0, preorder->size());
    }
};