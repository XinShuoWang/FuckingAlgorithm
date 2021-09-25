//
// Created by XinShuo Wang on 2021/9/23 9:23
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_326, 1) {
  using namespace std;
  class Solution {
   public:
    bool isPowerOfThree(int n) {
      unordered_set<int> s{
          1,       3,        9,        27,        81,        243,       729,
          2187,    6561,     19683,    59049,     177147,    531441,    1594323,
          4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
      return s.find(n) != s.end();
    }
  };
}