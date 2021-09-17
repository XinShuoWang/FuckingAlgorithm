//
// Created by XinShuo Wang on 2021/9/16 10:42
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_202, 1) {
  using namespace std;
  class Solution {
   public:
    bool isHappy(int n) {
      unordered_set<int> s;
      while (s.find(n) == s.end()) {
        s.insert(n);
        if ((n = work(n)) == 1) return true;
      }
      return false;
    }

    int work(int n) {
      int ans = 0;
      while (n != 0) {
        ans += (n % 10) * (n % 10);
        n /= 10;
      }
      return ans;
    }
  };
}