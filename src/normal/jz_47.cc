//
// Created by XinShuo Wang on 2021/10/11 9:39
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_47, 1) {
  using namespace std;
  class Solution {
    int ans = INT_MIN;

   public:
    int maxValue(vector<vector<int>>& grid) {
      work(grid, 0, 0, 0);
      return ans;
    }

    void work(vector<vector<int>>& grid, int x, int y, int v) {
      if (x == grid.size() - 1 && y == grid[0].size() - 1) {
        ans = max(ans, v + grid[x][y]);
        return;
      }
      if (y + 1 < grid[0].size()) work(grid, x, y + 1, v + grid[x][y]);
      if (x + 1 < grid.size()) work(grid, x + 1, y, v + grid[x][y]);
    }
  };
}

TEST(leetcode_jz_47, 2) {
  using namespace std;
  class Solution {
   public:
    int maxValue(vector<vector<int>>& grid) { return work(grid, 0, 0); }

    int work(vector<vector<int>>& grid, int x, int y) {
      if (x == grid.size() - 1 && y == grid[0].size() - 1) return grid[x][y];
      int a = 0, b = 0;
      if (y + 1 < grid[0].size()) a = work(grid, x, y + 1);
      if (x + 1 < grid.size()) b = work(grid, x + 1, y);
      return grid[x][y] + max(a, b);
    }
  };
}

TEST(leetcode_jz_47, 3) {
  using namespace std;
  class Solution {
   public:
    int maxValue(vector<vector<int>>& grid) {
      vector<vector<int>> v(grid);
      int m = grid.size(), n = grid[0].size(), i, j;
      for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
          v[i][j] = grid[i][j] + max(j - 1 >= 0 ? v[i][j - 1] : 0,
                                     i - 1 >= 0 ? v[i - 1][j] : 0);
        }
      }
      return v[m - 1][n - 1];
    }
  };
}