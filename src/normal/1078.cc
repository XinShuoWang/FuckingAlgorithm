//
// Created by XinShuo Wang on 2021/12/26 13:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_1078, 1) {
  using namespace std;
  class Solution {
   public:
    vector<string> findOcurrences(string& text, string& first, string& second) {
      vector<string> v, ans;
      int i = 0, j = 0;
      while (i < text.length()) {
        while (j < text.length() && text[j] != ' ') ++j;
        v.push_back(text.substr(i, j - i));
        //cout << text.substr(i, j - i) << endl;
        i = ++j;
      }
      for (int k = 0; k <= v.size() - 3; ++k) {
        if (v[k].length() == first.length() && v[k+1].length() == second.length() &&
            memcmp(v[k].c_str(), first.c_str(), first.length()) == 0 &&
            memcmp(v[k + 1].c_str(), second.c_str(), second.length()) == 0) {
          ans.push_back(v[k + 2]);
        }
      }
      return ans;
    }
  };
}