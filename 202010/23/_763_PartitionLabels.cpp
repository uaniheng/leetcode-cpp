//
// Created by gyc on 2020/10/22.
//

#include "../../common.h"

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int last[26];
        int length = S.size();
        for (int i = 0; i < length; i++) {
            last[S[i] - 'a'] = i;
        }

        vector<int> partition;
        int start = 0, end = 0;
        for (int i = 0; i < length; i++) {
            end = max(end, last[S[i] - 'a']);
            if (i == end) {
                partition.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
};

int main() {

    auto res = Solution().partitionLabels("ababcbacadefegdehijhklij");

    for(auto i: res) {
        cout << i << endl;
    }

}