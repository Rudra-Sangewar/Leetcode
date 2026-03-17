#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char ch, int r, int c) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == ch) return false;
            if (board[r][i] == ch) return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isvalid(board, ch, i, j)) {
                            board[i][j] = ch;

                            if (solve(board))
                                return true;

                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));

    cout << "Enter Sudoku (use . for empty cells):\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    Solution obj;
    obj.solveSudoku(board);

    cout << "\nSolved Sudoku:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}