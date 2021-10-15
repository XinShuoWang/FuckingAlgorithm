//
// Created by XinShuo Wang on 2021/10/11 9:04
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_10_1, 1) {
  using namespace std;
  class Solution {
   public:
    int fib(int n) {
      if (n <= 1) return n;
      vector<int> v(n + 1, 0);
      v[1] = 1;
      for (int i = 2; i <= n; ++i) {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000007;
      }
      return v[n];
    }
  };
}