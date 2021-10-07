//
// Created by XinShuo Wang on 2021/10/6 10:08
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_58, 1) {
  using namespace std;
  class Solution {
   public:
    string reverseLeftWords(string s, int n) {
      queue<char> q;
      for (char c : s) q.push(c);
      for (int i = 0; i < n; ++i) q.push(q.front()), q.pop();
      string ans;
      while (!q.empty()) ans.push_back(q.front()), q.pop();
      return ans;
    }
  };
}

TEST(leetcode_jz_58, 2) {
  using namespace std;
  class Solution {
   public:
    string reverseLeftWords(string s, int n) {
      string ans;
      for (int i = n; i < s.length(); ++i) ans.push_back(s[i]);
      for (int i = 0; i < n; ++i) ans.push_back(s[i]);
      return ans;
    }
  };
}

TEST(leetcode_jz_58, 3) {
  using namespace std;
  class Solution {
   public:
    string reverseLeftWords(string s, int n) {
      string ans;
      for (int i = n; i < n + s.length(); ++i) ans.push_back(s[i % s.length()]);
      return ans;
    }
  };
}