//
// Created by XinShuo Wang on 2021/9/3 12:43
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1091, 1) {
  using namespace std;
  class Solution {
   public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      if(grid[0][0] == 1) return -1;
      int ans = 0, m = grid.size(), n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      queue<pair<int, int>> q;
      q.push(make_pair(0, 0));
      visited[0][0] = true;
      while (!q.empty()) {
        int size = q.size();
        ans++;
        while (size > 0) {
          int x = q.front().first, y = q.front().second;
          if (x == m - 1 && y == n - 1) return ans;
          // 4
          if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == 0) {
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = true;
          }
          if (x + 1 <= m - 1 && !visited[x + 1][y] && grid[x + 1][y] == 0) {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = true;
          }
          if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == 0) {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = true;
          }
          if (y + 1 <= n - 1 && !visited[x][y + 1] && grid[x][y + 1] == 0) {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = true;
          }
          // 4
          if (x - 1 >= 0 && y - 1 >= 0 && !visited[x - 1][y - 1] &&
              grid[x - 1][y - 1] == 0) {
            q.push(make_pair(x - 1, y - 1));
            visited[x - 1][y - 1] = true;
          }
          if (x - 1 >= 0 && y + 1 <= n - 1 && !visited[x - 1][y + 1] &&
              grid[x - 1][y + 1] == 0) {
            q.push(make_pair(x - 1, y + 1));
            visited[x - 1][y + 1] = true;
          }
          if (x + 1 <= m - 1 && y - 1 >= 0 && !visited[x + 1][y - 1] &&
              grid[x + 1][y - 1] == 0) {
            q.push(make_pair(x + 1, y - 1));
            visited[x + 1][y - 1] = true;
          }
          if (x + 1 <= m - 1 && y + 1 <= n - 1 && !visited[x + 1][y + 1] &&
              grid[x + 1][y + 1] == 0) {
            q.push(make_pair(x + 1, y + 1));
            visited[x + 1][y + 1] = true;
          }
          q.pop();
          size--;
        }
      }
      return ans;
    }
  };
}