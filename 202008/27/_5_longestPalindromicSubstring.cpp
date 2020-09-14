//
// Created by gyc on 2020/8/24.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
private:
    int expandAroundCenter(string s, int left, int right) {
        int l = left, r = right;
        while (l >= 0 && r < s.length() && s.at(l) == s.at(r)){
            l --;
            r ++;
        }
        return r - l - 1;
    }
public:

    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int start = 0, end = 0;
        for (int i = 0; i < s.size() - 1; i ++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int* aa() {

}

class Demo{

private:
    int value[1];
public:
    Demo() {
        this->value[0] = 1;
        cout << "构造函数" << endl;
    }

    Demo( const Demo &obj) {
        this->value[0] = obj.value[0];
        cout << "复制构造" << endl;
    }

    ~Demo() {
        delete[] &value;
        cout << "析构函数" << endl;
    }

    int getValue() {
        return value[0];
    }
    void setValue(int value) {
        this->value[0] = value;
    }
};

Demo* test() {
    Demo demo;
    cout << demo.getValue() << endl;
    demo.setValue(22);
    return &demo;
}

int main() {
    //cout << Solution().longestPalindrome("cbbd") << endl;
    cout << test()->getValue() << endl;

}
