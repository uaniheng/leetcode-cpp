//
// Created by gyc on 2020/9/18.
//

#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif //LEETCODE_COMMON_H
