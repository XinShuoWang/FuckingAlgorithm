//
// Created by XinShuo Wang on 2021/9/1 12:54
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_200, 1) {
  using namespace std;
  class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
      vector<vector<bool>> visited(grid.size(),
                                   vector<bool>(grid[0].size(), false));
      int ans = 0;
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (!visited[i][j] && grid[i][j] == '1') {
            ans++;
            queue<pair<int, int>> q;
            q.push(make_pair(i, j));
            visited[i][j] = true;
            while (!q.empty()) {
              int x = q.front().first, y = q.front().second;
              q.pop();
              if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == '1') {
                q.push(make_pair(x - 1, y));
                visited[x - 1][y] = true;
              }
              if (x + 1 < grid.size() && !visited[x + 1][y] &&
                  grid[x + 1][y] == '1') {
                q.push(make_pair(x + 1, y));
                visited[x + 1][y] = true;
              }
              if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == '1') {
                q.push(make_pair(x, y - 1));
                visited[x][y - 1] = true;
              }
              if (y + 1 < grid[0].size() && !visited[x][y + 1] &&
                  grid[x][y + 1] == '1') {
                q.push(make_pair(x, y + 1));
                visited[x][y + 1] = true;
              }
            }
          }
        }
      }
      return ans;
    }
  };
}