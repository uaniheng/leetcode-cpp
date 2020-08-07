//
// Created by gyc on 2020/8/5.
//
#include <iostream>
#include <stack>

using namespace std;
int main() {

    for(int i = 0; i < 5; i ++) {
        //int arr[2]{i, i + 1};
        int *arr = new int[2]{i, i + 1};
        cout << arr << endl;
        delete[] arr;
    }
    return 0;
}

