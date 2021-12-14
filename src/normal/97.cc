//
// Created by XinShuo Wang on 2021/12/13 13:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_97, 1) {
  using namespace std;
  class Solution {
   public:
    bool dfs(string& s1, string& s2, string& s3, int i, int j, int k) {
      if (k >= s3.length()) return true;
      bool ans = false;
      if (i < s1.length() && s1[i] == s3[k]) ans = dfs(s1, s2, s3, i + 1, j, k + 1);
      if (ans) return ans;
      if (j < s2.length() && s2[j] == s3[k]) ans |= dfs(s1, s2, s3, i, j + 1, k);
      return ans;
    }

    bool isInterleave(string& s1, string& s2, string& s3) {
      return dfs(s1, s2, s3, 0, 0, 0);
    }
  };
}