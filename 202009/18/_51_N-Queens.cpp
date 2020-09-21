//
// Created by gyc on 2020/9/18.
//
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:

    vector<vector<string>> res;

    bool isValid(vector<string>& board, int row, int col) {

        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        for(int c = col + 1, r = row - 1; c < n && r >= 0; c ++, r --) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }

        for(int c = col - 1, r = row - 1; c >= 0 && r >= 0; c --, r --) {
            if (board[r][c] == 'Q') {
                return false;
            }
        }
        return true;
    }


    void solveRow(int row, vector<string>& board) {

        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for(int i = 0; i < n; i ++) {
            if (isValid(board, row, i)){
                board[row][i] = 'Q';
                solveRow(row + 1, board);
                board[row][i] = '.';
            }
        }
    }


public:
    vector<vector<string>> solveNQueens(int n) {

        // init board
        vector<string> board(n, string(n, '.'));

        solveRow(0, board);

        return res;
    }
};

int main() {

    auto res = Solution().solveNQueens(12);
    for(vector<string> str: res) {
        for (string row: str) {
            cout << row << endl;
        }
        cout << "=========================" << endl;
    }

}