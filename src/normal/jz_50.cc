//
// Created by XinShuo Wang on 2021/10/7 9:18
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_50, 1) {
  using namespace std;
  class Solution {
   public:
    char firstUniqChar(string s) {
      unordered_map<char, int> m;
      for (char c : s) {
        if (m.find(c) != m.end())
          m[c] += 1;
        else
          m[c] = 1;
      }
      for (char c : s) {
        if (m[c] == 1) return c;
      }
      return ' ';
    }
  };
}

TEST(leetcode_jz_50, 2) {
  using namespace std;
  class Solution {
   public:
    char firstUniqChar(string s) {
      int m[26] = {0};
      for (char c : s) {
        m[c - 'a'] += 1;
      }
      for (char c : s) {
        if (m[c - 'a'] == 1) return c;
      }
      return ' ';
    }
  };
}

TEST(leetcode_jz_50, 3) {
  using namespace std;
  class Solution {
   public:
    char firstUniqChar(string s) {
      int m[26] = {0}, count = 0;
      char n[26] = {' '};
      for (char c : s) {
        if (m[c - 'a'] == 0) {
          n[count++] = c;
        }
        m[c - 'a'] += 1;
      }
      for (int i = 0; i < count; ++i) {
        if (m[n[i] - 'a'] == 1) return n[i];
      }
      return ' ';
    }
  };
}