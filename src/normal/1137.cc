//
// Created by XinShuoWang on 2021/8/12.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_1137, 1) {
  using namespace std;
  class Solution {
   public:
    int tribonacci(int n) {
      int a = 0, b = 1, c = 1;
      if (n == 0) return a;
      if (n == 1) return b;
      if (n == 2) return c;
      int res = 0;
      for (int i = 3; i <= n; ++i) {
        res = a + b + c;
        a = b;
        b = c;
        c = res;
      }
      return res;
    }
  };
}

TEST(dp_1137, 2) {
  using namespace std;
  class Solution {
   public:
    int tribonacci(int n) {
      switch (n) {
        case 0:
          return 0;
        case 1:
          return 1;
        case 2:
          return 1;
        default:
          vector<int> v(4, 0);
          v[2] = v[1] = 1;
          for (int i = 3; i <= n; ++i) {
            v[i % 4] = v[(i - 1) % 4] + v[(i - 2) % 4] + v[(i - 3) % 4];
          }
          return v[n % 4];
      }
    }
  };
}