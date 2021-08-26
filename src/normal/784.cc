//
// Created by XinShuo Wang on 2021/8/25 19:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_784, 1) {
  using namespace std;
  class Solution {
    vector<string> ans;

   public:
    vector<string> letterCasePermutation(string s) {
      dfs(s, 0);
      return ans;
    }

    void dfs(string& s, int pos) {
      while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') pos++;
      if (pos == s.length()) {
        ans.push_back(s);
        return;
      }
      char c = s[pos];
      if (c >= 'A' && c <= 'Z') {
        s[pos] = 'a' + (c - 'A');
      } else {
        s[pos] = 'A' + (c - 'a');
      }
      dfs(s, pos + 1);
      s[pos] = c;
      dfs(s, pos + 1);
    }
  };
}