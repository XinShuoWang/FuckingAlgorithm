//
// Created by XinShuo Wang on 2021/8/25 18:41
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_994, 1) {
  using namespace std;
  class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<int, int>> q;
      set<pair<int, int>> s;
      vector<vector<bool>> visited(grid.size(),
                                   vector<bool>(grid[0].size(), false));
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
          if (grid[i][j] == 2) q.push(make_pair(i, j));
          if (grid[i][j] == 1) s.insert(make_pair(i, j));
        }
      }
      if (s.size() == 0) return 0;
      int ans = 0;
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          int x = q.front().first, y = q.front().second;
          visited[x][y] = true;
          s.erase(make_pair(x, y));
          if (x - 1 > -1 && grid[x - 1][y] == 1 && !visited[x - 1][y]) {
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = true;
          }
          if (x + 1 < grid.size() && grid[x + 1][y] == 1 &&
              !visited[x + 1][y]) {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = true;
          }
          if (y - 1 > -1 && grid[x][y - 1] == 1 && !visited[x][y - 1]) {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = true;
          }
          if (y + 1 < grid[0].size() && grid[x][y + 1] == 1 &&
              !visited[x][y + 1]) {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = true;
          }
          q.pop();
          size--;
        }
        ans++;
      }
      if (s.size() > 0) return -1;
      return ans - 1;
    }
  };
}