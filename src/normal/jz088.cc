//
// Created by XinShuoWang on 2021/8/12.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_jz_088, 1) {
  using namespace std;
  class Solution {
    map<int, int> cache;

   public:
    int minCostClimbingStairs(vector<int>& cost) {
      return min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(vector<int>& cost, int start) {
      if (start >= cost.size()) return 0;
      if (cache.count(start) != 0) return cache[start];
      int res = cost[start] + min(dfs(cost, start + 1), dfs(cost, start + 2));
      cache[start] = res;
      return res;
    }
  };
}