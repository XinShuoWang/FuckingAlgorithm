//
// Created by XinShuo Wang on 2021/10/11 9:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_63, 1) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      if (prices.size() == 0) return 0;
      int m = prices[0], v = 0;
      for (int i = 0; i < prices.size(); ++i) {
        v = max(v, prices[i] - m);
        m = min(m, prices[i]);
      }
      return v;
    }
  };
}