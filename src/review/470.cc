//
// Created by XinShuo Wang on 2021/9/5 9:33
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_470, 1) {
  using namespace std;
  int rand7();
  class Solution {
   public:
    int rand10() {
      int ans = 0;
      for (int i = 0; i < 10; ++i) {
        ans += rand7();
      }
      return ans / 10;
    }
  };
}