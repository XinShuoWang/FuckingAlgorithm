//
// Created by XinShuo Wang on 2021/8/17 12:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_557, 1) {
  using namespace std;
  class Solution {
   public:
    string reverseWords(string s) {
      int i = 0, j = 0;
      while (j < s.length()) {
        while (j < s.length() && s[j] != ' ') j++;
        reverse(s.begin() + i, s.begin() + j);
        i = ++j;
      }
      return s;
    }
  };
}