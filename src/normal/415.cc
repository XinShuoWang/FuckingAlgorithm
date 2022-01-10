//
// Created by XinShuo Wang on 2022/1/3 14:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_415, 1) {
  using namespace std;
  class Solution {
   public:
    string addStrings(string& num1, string& num2) {
      string ans;
      int i = num1.length() - 1, j = num2.length() - 1, p = 0;
      while (i >= 0 || j >= 0) {
        int x = (i >= 0 ? num1[i] : '0') - '0';
        int y = (j >= 0 ? num2[j] : '0') - '0';
        --i, --j;
        int t = x + y + p;
        p = t / 10, t %= 10;
        ans.push_back(char('0' + t));
      }
      if (p != 0) ans.push_back(char('0' + p));
      reverse(ans.begin(), ans.end());
      return ans;
    }
  };
}