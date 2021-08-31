//
// Created by XinShuo Wang on 2021/8/30 8:41
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_844, 1) {
  using namespace std;
  class Solution {
    string work(string& str) {
      string ans;
      for (char c : str) {
        if (c == '#') {
          if (ans.empty())
            continue;
          else
            ans.pop_back();
        } else {
          ans.push_back(c);
        }
      }
      return ans;
    }

   public:
    bool backspaceCompare(string s, string t) { return work(s) == work(t); }
  };
}

TEST(leetcode_844, 2) {
  using namespace std;
  class Solution {
   public:
    bool backspaceCompare(string s, string t) {
      int i = s.length() - 1, j = t.length() - 1;
      int a = 0, b = 0;
      while (i >= 0 || j >= 0) {
        while (i >= 0) {
          if (s[i] == '#') {
            a++, i--;
          } else if (a != 0) {
            a--, i--;
          } else {
            break;
          }
        }

        while (j >= 0) {
          if (t[j] == '#') {
            b++, j--;
          } else if (b != 0) {
            b--, j--;
          } else {
            break;
          }
        }

        if (i >= 0 && j >= 0) {
          if (s[i] != t[j]) {
            return false;
          }
        } else if (i < 0 && j < 0) {
          return true;
        } else {
          return false;
        }

        i--, j--;
      }
      return true;
    }
  };
}