//
// Created by XinShuo Wang on 2022/1/3 14:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_43, 1) {
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

    string multiply(string& num1, string& num2) {
      if(num1 == "0" || num2 == "0") return "0";
      vector<string> v;
      for (int i = num2.length() - 1; i >= 0; --i) {
        string temp;
        int p = 0, x = num2[i] - '0';
        for (int j = num1.length() - 1; j >= 0; --j) {
          int y = num1[j] - '0';
          int t = x * y + p;
          //cout << t << endl;
          p = t / 10, t %= 10;
          temp.push_back(char(t + '0'));
        }
        if (p) temp.push_back(p + '0');
        reverse(temp.begin(), temp.end());
        for (int j = 0; j < num2.length() - 1 - i; ++j) temp.push_back('0');
        //cout << temp << endl;
        v.emplace_back(temp);
      }
      string ans("0");
      for (string& num : v) ans = addStrings(ans, num);
      return ans;
    }
  };
}