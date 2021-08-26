//
// Created by XinShuo Wang on 2021/8/26 9:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_191, 1) {
  using namespace std;
  class Solution {
   public:
    int hammingWeight(uint32_t n) {
      int ans = 0;
      for (int i = 0; i < 33; ++i) {
        if (((1 << i) & n) == (1 << i)) ans++;
      }
      return ans;
    }
  };
}

TEST(leetcode_191, 2) {
  using namespace std;
  class Solution {
   public:
    int hammingWeight(uint32_t n) {
      int ans = 0;
      // 6&(6-1) = 4, 6 = (110)_2, 4 = (100)_2
      // 运算结果4即为把6的二进制位中的最低位的1变为0之后的结果。
      while (n != 0) n &= n - 1, ans++;
      return ans;
    }
  };
}