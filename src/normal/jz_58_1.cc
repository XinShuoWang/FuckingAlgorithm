//
// Created by XinShuo Wang on 2021/10/19 13:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_58_1, 1) {
  using namespace std;
  class Solution {
   public:
    string reverseWords(string s) {
      string ans = "";
      int i = 0, j = 0, flag = 0;
      while (i < s.length()) {
        while (i < s.length() && s[i] == ' ') ++i;
        j = i;
        while (j < s.length() && s[j] != ' ') ++j;
        if(i<s.length()){
          if (flag == 0) {
            ans = s.substr(i, j - i) + ans;
            flag = 1;
          } else {
            ans = s.substr(i, j - i) + " " + ans;
          }
        }
        i = j;
      }
      return ans;
    }
  };
}