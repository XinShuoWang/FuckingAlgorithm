//
// Created by XinShuo Wang on 2021/12/13 12:12
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_807, 1) {
  using namespace std;
  class Solution {
   public:
    void setRow(vector<vector<int>>& v, int n, int row, int val) {
      for (int i = 0; i < n; ++i) {
        v[row][i] = min(v[row][i], val);
      }
    }

    void setCol(vector<vector<int>>& v, int m, int col, int val) {
      for (int i = 0; i < m; ++i) {
        v[i][col] = min(v[i][col], val);
      }
    }

    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
      const int m = grid.size(), n = grid[0].size();
      vector<vector<int>> v(m, vector<int>(n, INT_MAX));
      for (int i = 0; i < m; ++i) {
        int ans = INT_MIN;
        for (int j = 0; j < n; ++j) {
          ans = max(ans, grid[i][j]);
        }
        setRow(v, n, i, ans);
      }
      for (int i = 0; i < n; ++i) {
        int ans = INT_MIN;
        for (int j = 0; j < m; ++j) {
          ans = max(ans, v[j][i]);
        }
        setCol(v, m, i, ans);
      }
      int ans = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          ans += v[i][j] - grid[i][j];
        }
      }
      return ans;
    }
  };
}