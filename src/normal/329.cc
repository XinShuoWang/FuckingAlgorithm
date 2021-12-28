//
// Created by XinShuo Wang on 2021/12/16 10:35
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_329, 1) {
  using namespace std;
  class Solution {
   public:
    int bfs(vector<vector<int>>& matrix, int x, int y) {
      auto combine = [](int i, int j) { return i + (j << 16); };
      auto split = [](int val) -> tuple<int, int> {
        return {val & 0x0000ffff, val >> 16};
      };
      const int m = matrix.size(), n = matrix[0].size();
      queue<int> q;
      q.push(combine(x, y));
      int level = 1;
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          auto [i, j] = split(q.front());
          q.pop(), size--;
          if (i + 1 < m && matrix[i + 1][j] > matrix[i][j])
            q.push(combine(i + 1, j));
          if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j])
            q.push(combine(i - 1, j));
          if (j + 1 < n && matrix[i][j + 1] > matrix[i][j + 1])
            q.push(combine(i, j + 1));
          if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j])
            q.push(combine(i, j - 1));
        }
        level++;
      }
      return level;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int ans = INT_MIN;
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          ans = max(ans, bfs(matrix, i, j));
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_329, 2) {
  using namespace std;
  class Solution {
    vector<vector<int>> cache;

   public:
    int dfs(vector<vector<int>>& matrix, int pre, int x, int y) {
      if (x >= matrix.size() || x < 0) return 0;
      if (y >= matrix[x].size() || y < 0) return 0;
      if(matrix[x][y] <= pre) return 0;
      if(cache[x][y] != -1) return cache[x][y];
      int ans = 1;
      ans = max(ans, dfs(matrix, matrix[x][y], x + 1, y) + 1);
      ans = max(ans, dfs(matrix, matrix[x][y], x - 1, y) + 1);
      ans = max(ans, dfs(matrix, matrix[x][y], x, y + 1) + 1);
      ans = max(ans, dfs(matrix, matrix[x][y], x, y - 1) + 1);
      cache[x][y] = ans;
      return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int ans = INT_MIN;
      const int m = matrix.size(), n = matrix[0].size();
      cache.resize(m, vector<int>(n, -1));
      for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
          ans = max(ans, dfs(matrix, -1, i, j));
        }
      }
      return ans;
    }
  };
}