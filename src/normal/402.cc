//
// Created by XinShuoWang on 2021/8/8.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(monotonic_stack_402, 1) {
  using namespace std;
  class Solution {
    vector<bool> v;

   public:
    string removeKdigits(string num, int k) {
      if (num.length() == k) return "0";
      v.resize(num.length(), false);
      return work(num, k);
    }

    string work(string num, int k) {
      if (k == 0) return num;
      string val(num.length(), '9');
      for (int i = 0; i < num.length(); ++i) {
        if (!v[i]) {
          string t = num;
          t = t.erase(i);
          v[i] = true;
          string tt = work(t, k - 1);
          if (tt.length() > val.length()) {
          } else if (tt.length() < val.length()) {
            val = tt;
          } else {
            int r = strcmp(val.c_str(), tt.c_str());
            if (r < 0) {
            } else if (r > 0) {
              val = tt;
            } else {
            }
          }
          v[i] = false;
        }
      }
      return val;
    }
  };
}