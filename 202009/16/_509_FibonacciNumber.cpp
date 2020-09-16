//
// Created by gyc on 2020/9/16.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N < 2) {
            return N;
        }
        int a = 0, b = 1;
        for(int i = 2; i <= N; i ++) {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};

int main() {
    cout << Solution().fib(4) << endl;

}