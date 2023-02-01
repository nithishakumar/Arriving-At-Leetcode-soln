#include<iostream>
#include<vector>
#include<set>

void travel(vector<vector<char>>& board, int r, int c) {
    if (r >= board.size() || c >= board[0].size() || board[r][c] == '*' || board[r][c] == 'X') {
        return;
    }
    board[r][c] = '*';
    travel(board, r + 1, c);
    travel(board, r - 1, c);
    travel(board, r, c - 1);
    travel(board, r, c + 1);
}
void solve(vector<vector<char>>& board) {
    for (int col = 0; col < board[0].size(); col++) {
        travel(board, 0, col);
        travel(board, board.size() - 1, col);
    }
    for (int row = 0; row < board.size(); row++) {
        travel(board, row, 0);
        travel(board, row, board[0].size() - 1);
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }
}