//
// Created by gyc on 2020/12/8.
//

#include "../../common.h"

class Solution {

private:
    bool backtrack(vector<int> &list, string s, int length, int index, int sum, int prev) {
        if (index == length) {
            return list.size() >= 3;
        }
        long long curr = 0;
        for(int i = index; i < length; ++i) {
            if(i > index && s[index] == '0') {
                break;
            }
            curr = curr * 10 + s[i] - '0';
            if (curr > INT32_MAX) {
                break;
            }
            if(list.size() >= 2) {
                if (curr < sum) {
                    continue;
                }else if(curr > sum) {
                    break;
                }
            }
            list.emplace_back(curr);
            if (backtrack(list, s, length, i + 1, prev + curr, curr)) {
                return true;
            }
            list.pop_back();
        }
        return false;
    }

public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> vec{};
        backtrack(vec, S, S.length(), 0, 0, 0);
        return vec;
    }
};
