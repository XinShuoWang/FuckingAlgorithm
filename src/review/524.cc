//
// Created by XinShuo Wang on 2021/12/14 13:13
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_524, 1) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int combine(int i, int j) {
      int ans = i;
      ans <<= 16;
      ans += j;
      return ans;
    }

    bool dfs(string& s1, string& s2, int i, int j) {
      if (j >= s2.length()) return true;
      if (i >= s1.length()) return false;
      if ((it = cache.find(combine(i, j))) != cache.end()) return it->second;
      bool ans = false;
      if (s1[i] == s2[j]) {
        ans |= dfs(s1, s2, i + 1, j + 1);
        if (ans) {
          cache[combine(i, j)] = ans;
          return ans;
        }
        ans |= dfs(s1, s2, i + 1, j);
      } else {
        ans |= dfs(s1, s2, i + 1, j);
      }
      cache[combine(i, j)] = ans;
      return ans;
    }

    bool ok(string& s1, string& s2) {
      if (s1.length() == s2.length() &&
          memcmp(s1.c_str(), s2.c_str(), s1.length()) == 0)
        return true;
      cache.clear();
      return dfs(s1, s2, 0, 0);
    }

    string findLongestWord(string& s, vector<string>& dictionary) {
      sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
        if (a.length() != b.length()) {
          return a.length() > b.length();
        } else {
          return memcmp(a.c_str(), b.c_str(), a.length()) < 0;
        }
      });
      for (auto& word : dictionary) {
        // cout << word << endl;
        if (word.length() <= s.length() && ok(s, word)) return word;
      }
      return "";
    }
  };
}

TEST(leetcode_524, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int combine(int i, int j) {
      int ans = i;
      ans <<= 16;
      ans += j;
      return ans;
    }

    bool dfs(string& s1, string& s2, int i, int j) {
      if (j >= s2.length()) return true;
      if (i >= s1.length()) return false;
      if ((it = cache.find(combine(i, j))) != cache.end()) return it->second;
      bool ans = false;
      if (s1[i] == s2[j]) {
        ans |= dfs(s1, s2, i + 1, j + 1);
        // 这里相比上一步使用了贪心算法
      } else {
        ans |= dfs(s1, s2, i + 1, j);
      }
      cache[combine(i, j)] = ans;
      return ans;
    }

    bool ok(string& s1, string& s2) {
      if (s1.length() == s2.length() &&
          memcmp(s1.c_str(), s2.c_str(), s1.length()) == 0)
        return true;
      cache.clear();
      return dfs(s1, s2, 0, 0);
    }

    string findLongestWord(string& s, vector<string>& dictionary) {
      sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
        if (a.length() != b.length()) {
          return a.length() > b.length();
        } else {
          return memcmp(a.c_str(), b.c_str(), a.length()) < 0;
        }
      });
      for (auto& word : dictionary) {
        // cout << word << endl;
        if (word.length() <= s.length() && ok(s, word)) return word;
      }
      return "";
    }
  };
}