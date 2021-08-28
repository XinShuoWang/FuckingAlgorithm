//
// Created by XinShuo Wang on 2021/8/27 15:32
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_190, 1) {
  using namespace std;
  class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
      queue<int> q;
      for (int i = 0; i < 32; ++i) {
        q.push(n & 1);
        n = n >> 1;
      }
      uint32_t ans = 0;
      while (!q.empty()) {
        ans = ans << 1;
        ans += q.front();
        q.pop();
      }
      return ans;
    }
  };
}