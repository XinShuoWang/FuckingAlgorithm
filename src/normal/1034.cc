//
// Created by XinShuo Wang on 2021/12/7 10:56
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1034, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col,
                                    int color) {
      queue<int> q;
      vector<array<int, 2>> s;
      int m = grid.size(), n = grid[0].size(), before = grid[row][col];
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      auto combine = [](int x, int y) { return (x << 16) + y; };
      q.push(combine(row, col));
      visited[row][col] = true;
      s.emplace_back(array<int, 2>{row, col});
      while (!q.empty()) {
        int y = q.front() & 0x0000ffff;
        int x = q.front() >> 16;
        q.pop();
        if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == before) {
          q.push(combine(x - 1, y));
          visited[x - 1][y] = true;
          s.emplace_back(array<int, 2>{x - 1, y});
        }
        if (x + 1 < m && !visited[x + 1][y] && grid[x + 1][y] == before) {
          q.push(combine(x + 1, y));
          visited[x + 1][y] = true;
          s.emplace_back(array<int, 2>{x + 1, y});
        }
        if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == before) {
          q.push(combine(x, y - 1));
          visited[x][y - 1] = true;
          s.emplace_back(array<int, 2>{x, y - 1});
        }
        if (y + 1 < n && !visited[x][y + 1] && grid[x][y + 1] == before) {
          q.push(combine(x, y + 1));
          visited[x][y + 1] = true;
          s.emplace_back(array<int, 2>{x, y + 1});
        }
      }
      // 是边界就返回true
      auto ok = [&](int x, int y) {
        if (x == 0 || x == m - 1 || y == 0 || y == n - 1) return true;
        if (!visited[x - 1][y] || !visited[x + 1][y] || !visited[x][y - 1] ||
            !visited[x][y + 1])
          return true;
        return false;
      };
      for (auto it : s) {
        if (ok(it[0], it[1])) grid[it[0]][it[1]] = color;
      }
      return grid;
    }
  };
}