//
// Created by XinShuo Wang on 2021/8/17 12:03
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_344, 1) {
  using namespace std;
  class Solution {
   public:
    void reverseString(vector<char>& s) {
      int i = 0, j = s.size() - 1;
      while (i < j) {
        swap(s[i++], s[j--]);
      }
    }
  };
}

TEST(leetcode_344, 2) {
  using namespace std;
  class Solution {
   public:
    void reverseString(vector<char>& s) {
      reverse(s.begin(), s.end());
    }
  };
}