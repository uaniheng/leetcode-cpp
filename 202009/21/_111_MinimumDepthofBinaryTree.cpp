//
// Created by gyc on 2020/9/21.
//
#include "../../common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {

public:
    int minDepth(TreeNode *root) {
        if (root == nullptr){
            return 0;
        }
        if (root->left != nullptr && root->right != nullptr) {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        } else {
            if (root->left != nullptr) {
                return minDepth(root->left) + 1;
            }
            return minDepth(root->right) + 1;
        }
    }
};

int main() {

    auto t1 = new TreeNode(3);
    auto t2 = new TreeNode(9);
    auto t3 = new TreeNode(20);
    auto t4 = new TreeNode(15);
    auto t5 = new TreeNode(7);

    t1->left = t2;
//    t1->right = t3;
//    t3->left = t4;
//    t3->right = t5;

    cout << Solution().minDepth(t1) << endl;
}
