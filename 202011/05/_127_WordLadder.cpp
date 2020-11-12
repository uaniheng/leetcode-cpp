//
// Created by gyc on 2020/11/5.
//

#include "../../common.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        if (beginWord == endWord) return 0;
        unordered_set<string> unvisited{};
        unordered_set<string> visited{};
        for (const auto &s: wordList) { unvisited.emplace(s); }
        queue<string> nodes{};
        nodes.emplace(beginWord);

        int d = 0;
        while (!nodes.empty()) {
            int size = nodes.size();
            for (int i = 0; i < size; ++i) {
                string s = nodes.front();
                nodes.pop();
                visited.emplace(s);
                if (s == endWord) {
                    return d + 1;
                }
                for(auto it = unvisited.begin(); it != unvisited.end();) {
                    int ne = 0;
                    for(int l = 0; l < beginWord.size(); ++l) {
                        if (s[l] != (*it)[l]){
                            ++ne;
                        }
                    }
                    if (ne == 1) {
                        if (!visited.count(*it)) {
                            nodes.emplace(*it);
                        }
                        unvisited.erase(it++);
                    }else {
                        ++it;
                    }
                }
            }
            ++d;
        }
        return 0;
    }
};

int main() {
    string beginWord = "a", endWord = "c";
    vector<string> wordList{"a", "b", "c"};
    cout << Solution().ladderLength(beginWord, endWord, wordList) << endl;
}