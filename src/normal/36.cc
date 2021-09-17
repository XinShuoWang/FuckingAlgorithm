//
// Created by XinShuo Wang on 2021/9/15 16:35
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_36, 1) {
  using namespace std;
  class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
      for (vector<char>& v : board) {
        if (!work(v)) return false;
      }
      for (int i = 0; i < 9; ++i) {
        vector<char> v(9, '.');
        for (int j = 0; j < 9; ++j) {
          v[j] = board[j][i];
        }
        if (!work(v)) return false;
      }
      for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
          vector<char> v(9, '.');
          v[0] = board[i][j];
          v[1] = board[i][j + 1];
          v[2] = board[i][j + 2];
          v[3] = board[i + 1][j];
          v[4] = board[i + 1][j + 1];
          v[5] = board[i + 1][j + 2];
          v[6] = board[i + 2][j];
          v[7] = board[i + 2][j + 1];
          v[8] = board[i + 2][j + 2];
          if (!work(v)) return false;
        }
      }
      return true;
    }

    bool work(vector<char>& v) {
      set<char> s;
      for (char c : v) {
        if (c != '.') {
          int size = s.size();
          s.insert(c);
          if (s.size() == size) return false;
        }
      }
      return true;
    }
  };
}