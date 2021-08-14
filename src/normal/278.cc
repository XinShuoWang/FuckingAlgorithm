//
// Created by XinShuo Wang on 2021/8/14 19:01
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_278, 1) {
  using namespace std;
  bool isBadVersion(int version);
  class Solution {
   public:
    int firstBadVersion(int n) {
      int left = -1, right = n;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (right - left == 1) return left;
        if (isBadVersion(mid)) {
          left = mid;
        } else {
          right = mid;
        }
      }
      return 0;
    }
  };
}