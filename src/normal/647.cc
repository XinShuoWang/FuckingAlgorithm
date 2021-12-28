//
// Created by XinShuo Wang on 2021/12/23 16:07
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_647, 1) {
  using namespace std;
  class Solution {
   public:
    int work(string& s, int left, int right) {
      const int n = s.length();
      while (left >= 0 && right < n && s[left] == s[right]) left--, right++;
      return right - left - 1;
    }

    int countSubstrings(string& s) {
      int ans = s.length(), n = s.length();
      for (int i = 0; i < n; ++i) {
        int a = work(s, i, i), b = work(s, i, i + 1);
        a = a / 2, b = b / 2;
        ans += a, ans += b;
      }
      return ans;
    }
  };
}