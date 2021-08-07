//
// Created by XinShuoWang on 2021/8/7.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_64, DFS) {
  using namespace std;
  class Solution {
    map<pair<int, int>, int> cache;

   public:
    int minPathSum(vector<vector<int>>& grid) { return work(grid, 0, 0); }

    int work(vector<vector<int>>& grid, int x, int y) {
      if (x < grid.size() && y < grid[0].size()) {
        if (cache.count(pair<int, int>(x, y)) != 0) {
          return cache[pair<int, int>(x, y)];
        }
        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
          return grid[x][y];
        }
        int a = work(grid, x + 1, y) + grid[x][y],
            b = work(grid, x, y + 1) + grid[x][y];
        cache[pair<int, int>(x, y)] = min(a, b);
        return min(a, b);
      }
      return 100000;
    }
  };
}

TEST(dp_64, dp) {
  using namespace std;
  class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
      int v[200][200];
      v[0][0] = grid[0][0];
      // 对于第0行的数据，只能是从左边过来
      for (int i = 1; i < grid[0].size(); ++i) {
        v[0][i] = v[0][i - 1] + grid[0][i];
      }
      // 对于第0列的数据，只能是从上边过来
      for (int i = 1; i < grid.size(); ++i) {
        v[i][0] = v[i - 1][0] + grid[i][0];
      }
      // 对于其他数据，可以从上面，也可以从左面过来
      for (int i = 1; i < grid.size(); ++i) {
        for (int j = 1; j < grid[0].size(); ++j) {
          v[i][j] = min(v[i - 1][j] + grid[i][j], v[i][j - 1] + grid[i][j]);
        }
      }
      return v[grid.size() - 1][grid[0].size() - 1];
    }
  };

  Solution solution;
  vector<vector<int>> data{{1, 2, 3}, {4, 5, 6}};
  solution.minPathSum(data);
}