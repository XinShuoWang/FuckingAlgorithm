//
// Created by XinShuo Wang on 2021/8/25 10:31
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_542, 1) {
  using namespace std;
  class Solution {
    int distance(vector<vector<int>>& mat, int x, int y) {
      queue<pair<int, int>> q;
      q.push(make_pair(x, y));
      int ans = 0;
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          int a = q.front().first, b = q.front().second;
          q.pop(), size--;
          if (mat[a][b] == 0) {
            return ans;
          }
          if (a - 1 > -1) q.push(make_pair(a - 1, b));
          if (a + 1 < mat.size()) q.push(make_pair(a + 1, b));
          if (b - 1 > -1) q.push(make_pair(a, b - 1));
          if (b + 1 < mat[0].size()) q.push(make_pair(a, b + 1));
        }
        ans++;
      }
      return ans;
    }

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
      for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
          ans[i][j] = mat[i][j] == 0 ? 0 : distance(mat, i, j);
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_542, 2) {
  using namespace std;
  class Solution {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited;

   public:
    // 这个思路是先找0的位置，以0的位置为起点进行BFS
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
      vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), 0));
      visited.resize(mat.size(), vector<bool>(mat[0].size(), false));
      for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
          if (mat[i][j] == 0) {
            q.push(make_pair(i, j));
          }
        }
      }

      int level = 0;
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          int a = q.front().first, b = q.front().second;
          size--, q.pop();
          if (!visited[a][b]) {
            ans[a][b] = level;
            visited[a][b] = true;
            if (a - 1 > -1 && !visited[a - 1][b])
              q.push(make_pair(a - 1, b));
            if (a + 1 < mat.size() && !visited[a + 1][b])
              q.push(make_pair(a + 1, b));
            if (b - 1 > -1 && !visited[a][b - 1])
              q.push(make_pair(a, b - 1));
            if (b + 1 < mat[0].size() && !visited[a][b + 1])
              q.push(make_pair(a, b + 1));
          }
        }
        level++;
      }
      return ans;
    }
  };
}