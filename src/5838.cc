//
// Created by XinShuoWang on 2021/8/8.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_5838, 1) {
  using namespace std;
  class Solution {
   public:
    bool memequ(const char* c1, const char* c2, int len) {
      for (int i = 0; i < len; ++i) {
        if (c1[i] != c2[i]) return false;
      }
      return true;
    }

    bool isPrefixString(string s, vector<string>& words) {
      int index = 0;
      for (int i = 0; i < words.size(); ++i) {
        if (index == s.length()) break;
        if (index + words[i].length() > s.length()) return false;
        if (memequ(&s[index], words[i].c_str(), words[i].length())) {
          index += words[i].length();
        } else {
          return false;
        }
      }
      if(index != s.length()) return false;
      return true;
    }
  };

  Solution solution;
  string s = "iloveleetcode";
  vector<string> v = {"i", "love", "leetcode", "apples"};
  cout << solution.isPrefixString(s, v) << endl;
}