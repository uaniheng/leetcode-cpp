//
// Created by gyc on 2021/2/24.
//

#include "../../common.h"

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {

        vector<vector<int>> res{};
        for(auto i = A.begin(); i != A.end(); ++i) {
            auto v = new vector<int>();
            for(auto j = i->begin(); j != i->end(); ++j) {
                v->emplace(v->begin(), 1^*j);
            }
            res.emplace_back(*v);
        }
        return res;
    }
};

int main() {

    vector<vector<int>> v{{1,1,0},{1,0,1},{0,0,0}};
    auto res = Solution().flipAndInvertImage(v);

}