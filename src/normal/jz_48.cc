//
// Created by XinShuo Wang on 2021/10/13 9:27
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_48, 1) {
  using namespace std;
  class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
      set<char> e;
      int ans = 0, i = 0, j = 0;
      while (i < s.length()) {
        while (j < s.length() && e.find(s[j]) == e.end()) {
          e.insert(s[j]);
          j++;
        }
        ans = max(ans, j - i);
        e.erase(s[i]);
        i++;
      }
      return ans;
    }
  };
}