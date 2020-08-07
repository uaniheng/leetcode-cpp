//
// Created by gyc on 2020/8/5.
//
#define NULL nullptr

#include <stack>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr) {
            return t2;
        }
        stack<TreeNode **> nodeStack{};
        nodeStack.push(new TreeNode*[2]{t1, t2});
        while (!nodeStack.empty()) {
            TreeNode **temp = nodeStack.top();
            nodeStack.pop();
            if (temp[1] == nullptr) {
                continue;
            }
            temp[0]->val += temp[1]->val;
            if (temp[0]->left == nullptr) {
                temp[0]->left = temp[1]->left;
            } else {
                nodeStack.push(new TreeNode*[2] {temp[0]->left, temp[1]->left});
            }
            if (temp[0]->right == nullptr) {
                temp[0]->right = temp[1]->right;
            } else {
                nodeStack.push(new TreeNode*[2]{temp[0]->right, temp[1]->right});
            }
        }
        return t1;
    }
};

int main() {

    TreeNode t1(1), t2(3), t3(2), t4(5);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;

    TreeNode tt1(2), tt2(1), tt3(3), tt4(4), tt5(7);
    tt1.left = &tt2;
    tt1.right = &tt3;
    tt2.right = &tt4;
    tt4.right = &tt5;

    TreeNode* r = Solution().mergeTrees(&t1, &tt1);
    cout << r->val << endl;
}
