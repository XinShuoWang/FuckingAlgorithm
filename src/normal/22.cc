//
// Created by XinShuo Wang on 2021/9/6 11:07
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_22, 1) {
  using namespace std;
  class Solution {
    vector<string> ans;
    string path;

   public:
    vector<string> generateParenthesis(int n) {
      path.push_back('(');
      work(2 * n - 1, 1, 0);
      return ans;
    }

    void work(int n, int left, int right) {
      if (right > left) return;
      if (n == 0) {
        if (left == right) ans.push_back(path);
        return;
      }
      for (char c : {'(', ')'}) {
        path.push_back(c);
        if (c == '(')
          work(n - 1, left + 1, right);
        else
          work(n - 1, left, right + 1);
        path.pop_back();
      }
    }
  };
}