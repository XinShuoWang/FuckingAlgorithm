//
// Created by XinShuo Wang on 2021/8/23 13:07
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_567, 1) {
  using namespace std;
  class Solution {
    bool isSame(map<char, int>& m1, map<char, int>& m2) {
      for (auto& kv : m1) {
        if (m2.count(kv.first) == 0) return false;
        if (m2[kv.first] != kv.second) return false;
      }
      return true;
    }

   public:
    bool checkInclusion(string s1, string s2) {
      int l1 = s1.length(), l2 = s2.length();
      if (l1 > l2) return false;
      map<char, int> m1, m2;
      for (int i = 0; i < l1; ++i) {
        if (m1.count(s1[i]) == 0)
          m1[s1[i]] = 1;
        else
          m1[s1[i]] += 1;
      }
      for (int i = 0; i < l1; ++i) {
        if (m2.count(s2[i]) == 0)
          m2[s2[i]] = 1;
        else
          m2[s2[i]] += 1;
      }
      if (isSame(m1, m2)) return true;
      for (int i = 1; i <= l2 - l1; ++i) {
        char a = s2[i - 1], b = s2[i + l1 - 1];
        m2[a] -= 1;
        if (m2[a] == 0) m2.erase(a);
        if (m2.count(b) == 0)
          m2[b] = 1;
        else
          m2[b] += 1;
        if (isSame(m1, m2)) return true;
      }
      return false;
    }
  };
}