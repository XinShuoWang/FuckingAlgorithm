//
// Created by XinShuo Wang on 2021/9/2 12:35
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_50, 1) {
  using namespace std;
  class Solution {
    double work(double x, long long n) {
      if (n == 1) return x;
      if (n % 2 == 0) {
        double ans = work(x, n / 2);
        return ans * ans;
      } else {
        double ans = work(x, (n - 1) / 2);
        return ans * ans * x;
      }
    }

   public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      if (n < 0) {
        return 1.0 / work(x, -1 * (long long)(n));
      } else {
        return work(x, n);
      }
    }
  };
}

TEST(leetcode_50, 2) {
  using namespace std;
  class Solution {
    // 这是把快速幂写成了迭代解法
    // n的二进制为：10010，则ans=x^2 * x^16
    double work(double x, long long n) {
      double ans = 1;
      while (n > 0) {
        if (n % 2 == 1) ans *= x;
        x *= x;
        n >>= 1;
      }
      return ans;
    }

   public:
    double myPow(double x, int n) {
      if (n == 0) return 1;
      if (n < 0) {
        return 1.0 / work(x, -1 * (long long)(n));
      } else {
        return work(x, n);
      }
    }
  };
}