//
// Created by XinShuo Wang on 2021/9/29 9:41
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_lcp07, 1) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = 0; }

    int numWays(int n, vector<vector<int>>& relation, int k) {
      unordered_map<int, vector<int>> r;
      for (vector<int>& v : relation) {
        int start = v[0], end = v[1];
        if (r.find(start) == r.end())
          r[start] = vector<int>{end};
        else
          r[start].push_back(end);
      }
      work(r, 0, n - 1, k);
      return ans;
    }

    void work(unordered_map<int, vector<int>>& r, int start, int target,
              int k) {
      if (k == 0) {
        if (start == target) ans++;
        return;
      }
      for (int s : r[start]) {
        work(r, s, target, k - 1);
      }
    }
  };
}