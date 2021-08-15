//
// Created by XinShuo Wang on 2021/8/15 10:33
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5843, 1) {
  using namespace std;
  class Solution {
   public:
    int numOfStrings(vector<string>& patterns, string word) {
      int res = 0;
      for (auto & pattern : patterns) {
        if (word.find(pattern) != word.npos) res++;
      }
      return res;
    }
  };
}