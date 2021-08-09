//
// Created by XinShuoWang on 2021/8/7.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_5, DFS) {
  using namespace std;
  class Solution {
    set<pair<int, int>> cache;

   public:
    string longestPalindrome(string s) {
      vector<string> v;
      for (int i = 0; i < s.length(); ++i) {
        for (int j = 1; j < s.length() - i; ++j) {
          //if()
          if (can(s, i, j)) {
            v.push_back(s.substr(i, j + 1));
          } else {
            pair<int, int> t;
            t.first = i;
            t.second = j;
            cache.insert(t);
          }
        }
      }
      string res = s.substr(0, 1);
      for (int i = 0; i < v.size(); ++i) {
        if (v[i].length() > res.length()) res = v[i];
      }
      return res;
    }

    bool can(string& s, int start, int len) {
      int end = start + len;
      while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
      }
      return true;
    }
  };
}