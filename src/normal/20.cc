//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(othres_20, 1) {
  using namespace std;
  class Solution {
   public:
    bool isValid(string s) {
      stack<char> ss;
      for (int i = 0; i < s.length(); ++i) {
        if (ss.empty()) {
          ss.push(s[i]);
        } else {
          if (match(ss.top(), s[i])) {
            ss.pop();
          } else {
            ss.push(s[i]);
          }
        }
      }
      return ss.empty();
    }

    inline bool match(char a, char b) {
      if (a == '(' && b == ')') return true;
      if (a == '{' && b == '}') return true;
      if (a == '[' && b == ']') return true;
      return false;
    }
  };

  Solution solution;
  solution.isValid("()");
}
