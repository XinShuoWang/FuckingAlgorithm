//
// Created by XinShuo Wang on 2021/9/26 15:10
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1020, 1) {
  using namespace std;
  class Solution {
   public:
    int numEnclaves(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();
      if (m == 1 || n == 1) return 0;
      queue<pair<int, int>> q;
      for (int i = 0; i < n; ++i) {
        if (grid[0][i] == 1) q.push(make_pair(0, i));
        if (grid[m - 1][i] == 1) q.push(make_pair(m - 1, i));
      }
      for (int i = 1; i < m - 1; ++i) {
        if (grid[i][0] == 1) q.push(make_pair(i, 0));
        if (grid[i][n - 1] == 1) q.push(make_pair(i, n - 1));
      }
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        grid[x][y] = 0;
        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
          grid[x - 1][y] = 0;
          q.push(make_pair(x - 1, y));
        }
        if (x + 1 < m && grid[x + 1][y] == 1) {
          grid[x + 1][y] = 0;
          q.push(make_pair(x + 1, y));
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
          grid[x][y - 1] = 0;
          q.push(make_pair(x, y - 1));
        }
        if (y + 1 < n && grid[x][y + 1] == 1) {
          grid[x][y + 1] = 0;
          q.push(make_pair(x, y + 1));
        }
        q.pop();
      }
      int ans = 0;
      for (int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j){
          ans += grid[i][j];
        }
      }
      return ans;
    }
  };
}