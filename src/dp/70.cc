//
// Created by xinsh on 2021/8/1.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_70, 1) {
  using namespace std;
  class Solution {
   public:
    int climbStairs(int n) {
      if (n <= 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      return climbStairs(n - 1) + climbStairs(n - 2);
    }
  };
}

TEST(dp_70, 2) {
  using namespace std;
  class Solution {
   public:
    int climbStairs(int n) {
      if (n <= 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      int data[10000];
      data[1] = 1;
      data[2] = 2;
      for (int i = 3; i <= n; ++i) {
        data[i] = data[i - 1] + data[i - 2];
      }
      return data[n];
    }
  };
}