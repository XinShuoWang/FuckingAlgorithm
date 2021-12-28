//
// Created by XinShuo Wang on 2021/12/18 14:09
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_419, 1) {
  using namespace std;
  class Solution {
   public:
    void visit(vector<vector<char>>& board, vector<vector<bool>>& visited,
               int i, int j) {
      const int m = board.size(), n = board[0].size();
      if (i < 0 || i >= m) return;
      if (j < 0 || j >= n) return;
      if (board[i + 1][j] == 'X' && !visited[i + 1][j]) {
        visited[i + 1][j] = true;
        visit(board, visited, i + 1, j);
      }
      if (board[i - 1][j] == 'X' && !visited[i - 1][j]) {
        visited[i - 1][j] = true;
        visit(board, visited, i - 1, j);
      }
      if (board[i][j + 1] == 'X' && !visited[i][j + 1]) {
        visited[i][j + 1] = true;
        visit(board, visited, i, j + 1);
      }
      if (board[i][j - 1] == 'X' && !visited[i][j - 1]) {
        visited[i][j - 1] = true;
        visit(board, visited, i, j - 1);
      }
    }

    int countBattleships(vector<vector<char>>& board) {
      const int m = board.size(), n = board[0].size();
      int ans = 0;
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (board[i][j] == 'X' && !visited[i][j]) {
            visited[i][j] = true;
            visit(board, visited, i, j);
            ans++;
          }
        }
      }
      return ans;
    }
  };
}