//
// Created by XinShuo Wang on 2021/8/26 9:50
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_231, 1) {
  using namespace std;
  class Solution {
   public:
    bool isPowerOfTwo(int n) {
      if (n <= 0) return false;
      for (int i = 0; i < 31; ++i) {
        if ((n & (1 << i)) == n) return true;
      }
      return false;
    }
  };
}

TEST(leetcode_231, 2) {
  using namespace std;
  class Solution {
   public:
    bool isPowerOfTwo(int n) { return n > 0 && ((n & (n - 1)) == 0); }
  };
}