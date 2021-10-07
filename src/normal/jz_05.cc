//
// Created by XinShuo Wang on 2021/10/6 10:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_05, 1) {
  using namespace std;
  class Solution {
   public:
    string replaceSpace(string s) {
      string ans;
      for (char c : s) {
        if (c == ' ')
          ans.append("%20");
        else
          ans.push_back(c);
      }
      return ans;
    }
  };
}