//
// Created by gyc on 2020/8/6.
//
#include <iostream>

#define NULL nullptr


using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // 记录累加总和
    int sum = 0;
public:
    TreeNode *convertBST(TreeNode *root) {
        // 中根序遍历
        if (root == nullptr)
            return root;
        convertBST(root->right);
        sum += root->val;
        root->val = sum;
        convertBST(root->left);
        return root;
    }
};

int main() {

    TreeNode t1(2), tt2(1), tt3(3), tt4(4), tt5(7);

    cout << Solution().convertBST(&t1)->val << endl;

}
