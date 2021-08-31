//
// Created by XinShuo Wang on 2021/8/31 9:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_438, 1) {
  using namespace std;
  class Map {
   private:
    map<char, int> m;

   public:
    void insert(char c) {
      if (m.find(c) != m.end()) {
        m[c] += 1;
      } else {
        m[c] = 1;
      }
    }

    bool operator==(Map& map) {
      for (auto& kv : m) {
        if (map.m.find(kv.first) == map.m.end()) return false;
        if (map.m[kv.first] != kv.second) return false;
      }
      return true;
    }

    void decrement(char c) {
      if (m.find(c) != m.end()) {
        if (m[c] == 1) {
          m.erase(c);
        } else {
          m[c] -= 1;
        }
      }
    }

    int get(char c) {
      if (m.find(c) != m.end()) {
        return m[c];
      }
      return -1;
    }
  };
  class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
      if (s.length() < p.length()) return vector<int>{};
      vector<int> ans;
      Map m1, m2;
      for (char c : p) {
        m1.insert(c);
      }
      int i;
      for (i = 0; i < p.length(); ++i) {
        m2.insert(s[i]);
      }
      if (m1 == m2) ans.push_back(0);
      for (i = p.length(); i < s.length(); ++i) {
        m2.decrement(s[i - p.length()]);
        m2.insert(s[i]);
        if (m1 == m2) ans.push_back(i - p.length() + 1);
      }
      return ans;
    }
  };
}