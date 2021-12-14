//
// Created by XinShuo Wang on 2021/12/13 14:03
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_720, 1) {
  using namespace std;
  class Solution {
   public:
    string longestWord(vector<string>& words) {
      set<string> s(words.begin(), words.end());
      queue<string> q;
      vector<string> ans;
      for (auto& word : words) {
        if (word.length() == 1) {
          ans.push_back(word);
          q.push(word);
        }
      }
      while (!q.empty()) {
        string t = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
          if (s.find(t + (char)('a' + i)) != s.end()) {
            q.push(t + (char)('a' + i));
            ans.push_back(t + (char)('a' + i));
          }
        }
      }
      if (ans.empty()) return "";
      sort(ans.begin(), ans.end(), [](string& a, string& b) {
        if (a.length() == b.length()) {
          return memcmp(a.c_str(), b.c_str(), a.length()) < 0;
        } else {
          return a.length() > b.length();
        }
      });
      return ans[0];
    }
  };
}

TEST(leetcode_720, 2) {
  using namespace std;
  class Solution {
   public:
    string longestWord(vector<string>& words) {
      set<string> s(words.begin(), words.end());
      queue<string> q;
      string ans;
      sort(words.begin(), words.end(), [](string& a, string& b) {
        if (a.length() == b.length()) {
          return memcmp(a.c_str(), b.c_str(), a.length()) < 0;
        } else {
          return a.length() > b.length();
        }
      });
      for (auto& word : words) {
        if (word.length() == 1) {
          if (word.length() > ans.length()) ans = word;
          q.push(word);
        }
      }
      while (!q.empty()) {
        string t = q.front();
        q.pop();
        for (int i = 0; i < 26; ++i) {
          string tt = t + (char)('a' + i);
          if (s.find(tt) != s.end()) {
            q.push(tt);
            if (tt.length() > ans.length()) ans = tt;
          }
        }
      }
      return ans;
    }
  };
}