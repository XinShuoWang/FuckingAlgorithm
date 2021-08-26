//
// Created by XinShuo Wang on 2021/8/25 19:24
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_77, 1) {
  using namespace std;
  class Solution {
   private:
    vector<bool> visited;
    vector<vector<int>> ans;
    vector<int> path;

   public:
    vector<vector<int>> combine(int n, int k) {
      visited.resize(n + 1, false);
      dfs(1, n, k);
      return ans;
    }

    void dfs(int s, int n, int k) {
      if (k == 0) {
        ans.push_back(path);
        return;
      }
      // 这个循环会保证1在被第一次循环结束之后就不再被使用，以此类推2,3,4，。。。
      for (int i = s; i <= n; ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.push_back(i);
          // 这里传入i+1是为了防止[1,3,5]和[1,5,3]这种情况出现，保证单调性
          dfs(i + 1, n, k - 1);
          path.pop_back();
          visited[i] = false;
        }
      }
    }
  };
}