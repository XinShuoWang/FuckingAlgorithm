//
// Created by XinShuo Wang on 2021/8/22 12:22
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_3, 1) {
  using namespace std;
  class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
      if (s.length() == 0) return 0;
      int res = 0;
      for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
          if (work(s, i, j)) res = max(res, j - i + 1);
        }
      }
      return res;
    }

    bool work(string& s, int start, int end) {
      set<char> ss;
      for (int i = start; i <= end; ++i) {
        if (ss.count(s[i]) != 0) return false;
        ss.insert(s[i]);
      }
      return true;
    }
  };
}

TEST(leetcode_3, 2) {
  using namespace std;
  class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
      if (s.length() == 0) return 0;
      set<char> ss;
      int j = 0, ans = 0;
      for (int i = 0; i < s.length(); ++i) {
        if (i != 0) {
          ss.erase(s[i - 1]);
        }
        while (j < s.length() && ss.count(s[j]) == 0) {
          ss.insert(s[j]);
          j++;
        }
        ans = max(ans, j - i);
      }
      return ans;
    }
  };

  Solution solution;
  cout << solution.lengthOfLongestSubstring("bbbbb") << endl;
}