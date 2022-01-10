//
// Created by XinShuo Wang on 2021/12/31 11:50
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_463, 1) {
  using namespace std;
  class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
      stack<int> island;
      int m = grid.size(), n = grid[0].size();
      auto combine = [](int x, int y) { return (x << 16) + y; };
      auto split = [](int v) { return make_tuple(v >> 16, v & 0x0000ffff); };
      auto eval = [](vector<vector<int>>& grid, int i, int j) {
        int ans = 0, mm = grid.size(), nn = grid[0].size();
        if (i - 1 == -1 || (i - 1 >= 0 && grid[i - 1][j] == 0)) ans++;
        if (i + 1 == mm || (i + 1 < mm && grid[i + 1][j] == 0)) ans++;
        if (j - 1 == -1 || (j - 1 >= 0 && grid[i][j - 1] == 0)) ans++;
        if (j + 1 == nn || (j + 1 < nn && grid[i][j + 1] == 0)) ans++;
        return ans;
      };
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == 1) {
            island.push(combine(i, j));
            visited[i][j] = true;
            goto cal;
          }
        }
      }
    cal:
      int ans = 0;
      while (!island.empty()) {
        auto [x, y] = split(island.top());
        island.pop();
        ans += eval(grid, x, y);
        if (x - 1 >= 0 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
          visited[x - 1][y] = true;
          island.push(combine(x - 1, y));
        }
        if (x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
          visited[x + 1][y] = true;
          island.push(combine(x + 1, y));
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
          visited[x][y - 1] = true;
          island.push(combine(x, y - 1));
        }
        if (y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
          visited[x][y + 1] = true;
          island.push(combine(x, y + 1));
        }
      }
      return ans;
    }
  };
}