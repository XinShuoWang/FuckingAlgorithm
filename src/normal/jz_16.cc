//
// Created by XinShuo Wang on 2021/10/23 9:47
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_16, 1) {
  using namespace std;
  class Solution {
   public:
    double myPow(double x, int n) {
      long long p = n;
      if (p == 0) return 1;
      if (p < 0) return 1.0 / work(x, -p);
      return work(x, p);
    }

    double work(double x, int n) {
      if (n == 1) return x;
      if (n % 2 == 0) {
        double ans = myPow(x, n / 2);
        return ans * ans;
      } else {
        double ans = myPow(x, (n - 1) / 2);
        return ans * ans * x;
      }
    }
  };
}