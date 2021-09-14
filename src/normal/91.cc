//
// Created by XinShuo Wang on 2021/9/10 11:55
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_91, 1) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int numDecodings(string s) { return work(s, 0); }

    int work(string& s, int pos) {
      if ((it = cache.find(pos)) != cache.end()) return it->second;
      if (pos >= s.length()) {
        return 1;
      }
      int ans = 0;
      char a = s[pos];
      if (a <= '9' && a >= '1') {
        ans += work(s, pos + 1);
      }
      if (pos <= s.length() - 2) {
        char b = s[pos + 1];
        if (a == '1' && b >= '0' && b <= '9') {
          ans += work(s, pos + 2);
        } else if (a == '2' && b >= '0' && b <= '6') {
          ans += work(s, pos + 2);
        }
      }
      cache[pos] = ans;
      return ans;
    }
  };
}