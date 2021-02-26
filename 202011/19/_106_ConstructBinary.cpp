//
// Created by gyc on 2020/11/19.
//
#include "../../common.h"

class Solution {

private:
    vector<int> *inorder, *postorder;

    TreeNode *build(int inBegin, int postBegin, int size) {
        if (inBegin >= inorder->size() || postBegin >= postorder->size() || size < 1) {
            return nullptr;
        }
        int lSize = 0;
        while (inorder[inBegin] != postorder[postBegin + size - 1]) {
            ++lSize;
        }
        auto *root = new TreeNode((*inorder)[inBegin]);
        root->left = build(inBegin - lSize, postBegin, lSize);
        root->right = build(inBegin + 1, postBegin + lSize, size - lSize - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder1, vector<int> &postorder1) {
        inorder = &inorder1;
        postorder = &postorder1;
        return build(0, 0, inorder1.size());
    }
};