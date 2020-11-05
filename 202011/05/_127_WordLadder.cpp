//
// Created by gyc on 2020/11/5.
//

#include "../../common.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord == endWord) return 0;


        unordered_set<string> unvisited{};
        queue<string> nodes{};
        int res = INT32_MAX, d = 0;
        for (const auto &e: wordList) {
            unvisited.insert(e);
        }
        nodes.emplace(beginWord);

        while (!nodes.empty()) {
            ++d;
            int s = nodes.size();
            for(int c = 0; c < s; ++c) {
                string node = nodes.front();
                nodes.pop();
                if (node == endWord) {
                    res = min(res, d);
                }
                for (auto it = unvisited.begin(); it != unvisited.end();) {
                    string str = *it;
                    int ne = 0;
                    for (int i = 0; i < node.size(); ++i) {
                        if (node[i] != str[i]) {
                            ne++;
                        }
                    }
                    if (ne == 1) {
                        unvisited.erase(it++);
                        nodes.push(str);
                    }else{
                        ++it;
                    }
                }
            }
        }
        return res == INT32_MAX ? 0 : res;
    }
};

int main() {
    string beginWord = "a", endWord = "c";
    vector<string> wordList{"a","b","c"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
}