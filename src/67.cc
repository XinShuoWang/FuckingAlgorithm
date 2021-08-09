//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(othres_67, 1) {
  using namespace std;
  class Solution {
   public:
    string addBinary(string a, string b) {
      reverse(a.begin(), a.end());
      reverse(a.begin(), a.end());
      int cf = 0, id = 0;
      string res = "";
      while (id < max(a.length(), b.length())) {
        char aa = '0', bb = '0';
        if (id < a.length()) aa = a[id];
        if (id < b.length()) bb = b[id];
        id++;
        res.push_back(add(aa, bb, cf));
      }
      if (cf == 1) res.push_back('1');
      reverse(res.begin(), res.end());
      return res;
    }

    inline char add(char a, char b, int& cf) {
      if (a == '0' && b == '0') {
        if (cf == 0) {
          cf = 0;
          return '0';
        } else {
          cf = 0;
          return '1';
        }
      } else if ((a == '1' && b == '0') || (a == '0' && b == '1')) {
        if (cf == 0) {
          cf = 0;
          return '1';
        } else {
          cf = 1;
          return '0';
        }
      } else if (a == '1' && b == '1') {
        if (cf == 0) {
          cf = 1;
          return '0';
        } else {
          cf = 1;
          return '1';
        }
      }
      return '0';
    }
  };
}
