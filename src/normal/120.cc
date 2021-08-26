//
// Created by XinShuo Wang on 2021/8/26 10:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_120, 1) {
  using namespace std;
  class Solution {
    int ans = INT_MAX;

   public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.size() == 1) return triangle[0][0];
      dfs(triangle, 0, 0, 0);
      return ans;
    }

    void dfs(vector<vector<int>>& triangle, int x, int y, int val) {
      if (x == triangle.size() - 1) {
        ans = min(ans, val + triangle[x][y]);
        return;
      }
      dfs(triangle, x + 1, y, val + triangle[x][y]);
      if (triangle[x + 1].size() > y + 1)
        dfs(triangle, x + 1, y + 1, val + triangle[x][y]);
    }
  };
}

TEST(leetcode_120, 2) {
  using namespace std;
  class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
      if (triangle.size() == 1) return triangle[0][0];
      vector<vector<int>> ans(triangle);
      for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
          ans[i][j] = INT_MAX;
        }
      }
      ans[0][0] = triangle[0][0];
      for (int i = 0; i < triangle.size() - 1; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
          if (ans[i + 1][j] == INT_MAX)
            ans[i + 1][j] = ans[i][j] + triangle[i + 1][j];
          else
            ans[i + 1][j] = min(ans[i][j] + triangle[i + 1][j], ans[i + 1][j]);
          if (ans[i + 1][j + 1] == INT_MAX)
            ans[i + 1][j + 1] = ans[i][j] + triangle[i + 1][j + 1];
          else
            ans[i + 1][j + 1] =
                min(ans[i][j] + triangle[i + 1][j + 1], ans[i + 1][j + 1]);
        }
      }
      return *min_element(ans[ans.size() - 1].begin(),
                          ans[ans.size() - 1].end());
    }
  };
}