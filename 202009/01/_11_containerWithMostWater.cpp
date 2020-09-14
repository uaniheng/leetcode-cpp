//
// Created by gyc on 2020/8/24.
//
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            if (height[i] == 0) {
                continue;
            }
            for (int j = maxArea / height[i] + i; j < height.size(); j++) {
                if (min(height[i], height[j]) * (j - i) > maxArea) {
                    maxArea = min(height[i], height[j]) * (j - 1);
                }
            }
        }

        return maxArea;

    }
};

int main() {
    vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << Solution().maxArea(v1) << endl;
}