//
// Created by xinsh on 2021/8/1.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(trick_p1226, 1226) {
  class Solution {
   public:
    long long mypow(long long a, long long b, long long p) {
      if (b == 0) return 1;
      if (b % 2 == 0) {
        long long t = mypow(a, b / 2, p) % p;
        return t * t % p;
      } else {
        return mypow(a, b - 1, p) * a % p;
      }
    }

    int main() {
      long long a, b, p;
      scanf("%lld%lld%lld", &a, &b, &p);
      printf("%lld^%lld mod %lld=%lld", a, b, p, mypow(a, b, p));
      return 0;
    }
  };

  Solution solution;
  solution.main();
}