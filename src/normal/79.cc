//
// Created by XinShuo Wang on 2021/9/6 9:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_79, 1) {
  using namespace std;
  class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          vector<vector<bool>> visited(board.size(),
                                       vector<bool>(board[0].size(), false));
          visited[i][j] = true;
          if (board[i][j] == word[0] && work(board, word, visited, 1, i, j))
            return true;
        }
      }
      return false;
    }

    bool work(vector<vector<char>>& board, string word,
              vector<vector<bool>>& visited, int pos, int x, int y) {
      if (pos == word.length()) return true;
      if (x - 1 >= 0 && board[x - 1][y] == word[pos] && !visited[x - 1][y]) {
        visited[x - 1][y] = true;
        if (work(board, word, visited, pos + 1, x - 1, y)) return true;
        visited[x - 1][y] = false;
      }
      if (x + 1 < board.size() && board[x + 1][y] == word[pos] &&
          !visited[x + 1][y]) {
        visited[x + 1][y] = true;
        if (work(board, word, visited, pos + 1, x + 1, y)) return true;
        visited[x + 1][y] = false;
      }
      if (y - 1 >= 0 && board[x][y - 1] == word[pos] && !visited[x][y - 1]) {
        visited[x][y - 1] = true;
        if (work(board, word, visited, pos + 1, x, y - 1)) return true;
        visited[x][y - 1] = false;
      }
      if (y + 1 < board[0].size() && board[x][y + 1] == word[pos] &&
          !visited[x][y + 1]) {
        visited[x][y + 1] = true;
        if (work(board, word, visited, pos + 1, x, y + 1)) return true;
        visited[x][y + 1] = false;
      }
      return false;
    }
  };
}