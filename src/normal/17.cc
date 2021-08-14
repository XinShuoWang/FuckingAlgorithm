//
// Created by XinShuo Wang on 2021/8/14 0:35
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_17, 1) {
  using namespace std;
  class Solution {
    vector<string> res;
    string path;
    map<char, string> m;

   public:
    Solution() {
      path = "";
      m['2'] = "abc";
      m['3'] = "def";
      m['4'] = "ghi";
      m['5'] = "jkl";
      m['6'] = "mno";
      m['7'] = "pqrs";
      m['8'] = "tuv";
      m['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
      if(digits.length()==0) return vector<string>{};
      work(digits, 0);
      return res;
    }

    void work(string& digits, int pos) {
      if (pos == digits.length()) {
        res.push_back(path);
        return;
      }
      for (int i = 0; i < m[digits[pos]].length(); ++i) {
        path.push_back(m[digits[pos]][i]);
        work(digits, pos + 1);
        path.pop_back();
      }
    }
  };
}