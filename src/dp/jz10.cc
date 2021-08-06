//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_jz10, 1) {
  using namespace std;
  class Solution {
    typedef long long ll;

   public:
    int fib(int n) {
      if (n == 0) return 0;
      if (n == 1) return 1;
      ll a = 0, b = 1, t;
      for (int i = 2; i <= n; ++i) {
        t = (a + b) % (ll)(1e9 + 7);
        a = b;
        b = t;
      }
      return t % (ll)(1e9 + 7);
    }
  };
}
