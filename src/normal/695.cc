//
// Created by XinShuo Wang on 2021/8/24 9:51
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_695, 1) {
  using namespace std;
  class Solution {
    vector<vector<bool>> visited;
    int bfs(vector<vector<int>>& grid, int i, int j) {
      queue<pair<int, int>> q;
      int ans = 0;
      q.push(make_pair(i, j));
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (!visited[x][y]) {
          visited[x][y] = true;
          ans++;
          if (x - 1 > -1 && grid[x - 1][y] == 1) q.push(make_pair(x - 1, y));
          if (x + 1 < grid.size() && grid[x + 1][y] == 1)
            q.push(make_pair(x + 1, y));
          if (y - 1 > -1 && grid[x][y - 1] == 1) q.push(make_pair(x, y - 1));
          if (y + 1 < grid[0].size() && grid[x][y + 1] == 1)
            q.push(make_pair(x, y + 1));
        }
      }
      return ans;
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int ans = 0;
      visited.resize(grid.size(), vector<bool>(grid[0].size(), false));
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 1 && !visited[i][j]) {
            ans = max(ans, bfs(grid, i, j));
          }
        }
      }
      return ans;
    }
  };

  Solution solution;
  vector<vector<int>> v = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  solution.maxAreaOfIsland(v);
}