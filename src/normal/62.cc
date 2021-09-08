//
// Created by XinShuo Wang on 2021/9/8 9:14
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_62, 1) {
  using namespace std;
  class Solution {
    int ans = 0;

   public:
    int uniquePaths(int m, int n) {
      work(m, n, 1, 1);
      return ans;
    }

    void work(int m, int n, int x, int y) {
      if (x == m && y == n) {
        ans++;
        return;
      }
      if (x + 1 <= m) work(m, n, x + 1, y);
      if (y + 1 <= n) work(m, n, x, y + 1);
    }
  };
}

TEST(leetcode_62, 2) {
  using namespace std;
  class Solution {
   public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> v(m, vector<int>(n, 0));
      for (int i = 0; i < n; ++i) {
        v[0][i] = 1;
      }
      for (int i = 0; i < m; ++i) {
        v[i][0] = 1;
      }
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
          v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
      }
      return v[m - 1][n - 1];
    }
  };
}