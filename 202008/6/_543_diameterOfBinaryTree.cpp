//
// Created by gyc on 2020/8/6.
//
/**
 * Definition for a binary tree node.
 */

#include <iostream>

#define NULL nullptr

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int ans;

    int max(int a, int b) {
        return a > b ? a : b;
    }

    int depth(TreeNode *node) {
        if (node == nullptr) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};


int main() {
    TreeNode tt1(2), tt2(1), tt3(3), tt4(4), tt5(7);
    tt1.left = &tt2;
    tt1.right = &tt3;
    tt2.right = &tt4;
    tt4.right = &tt5;

    cout << Solution().diameterOfBinaryTree(&tt1) << endl;
}