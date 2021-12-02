//
// Created by XinShuoWang on 2021/8/7.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_5, DFS) {
  using namespace std;
  class Solution {
   public:
    string longestPalindrome(string s) {
      int len = INT_MIN;
      string ans;
      for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
          if (j - i > len && can(s, i, j)) {
            ans = s.substr(i, j - i + 1);
            len = j - i;
          }
        }
      }
      return ans;
    }

    bool can(string& s, int start, int end) {
      while (start < end) {
        if (s[start] != s[end]) return false;
        start++;
        end--;
      }
      return true;
    }
  };
}

TEST(dp_5, 2) {
  using namespace std;
  class Solution {
   public:
    string longestPalindrome(string s) {
      int max_len = 1;
      string ans = s.substr(0, 1);
      for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j < s.length(); ++j) {
          int len = j - i + 1;
          if (work(s, i, j) && len > max_len) {
            max_len = len;
            ans = s.substr(i, len);
          }
        }
      }
      return ans;
    }

    bool work(string& s, int start, int end) {
      if (start >= end) return true;
      return s[start] == s[end] && work(s, start + 1, end - 1);
    }
  };
}

TEST(dp_5, 3) {
  using namespace std;
  class Solution {
    unordered_map<uint64_t, bool> cache;
    unordered_map<uint64_t, bool>::iterator it;

    uint64_t make(uint32_t x, uint32_t y) {
      uint64_t ans = x;
      ans <<= 32;
      return ans + y;
    }

   public:
    string longestPalindrome(string s) {
      int max_len = 1;
      string ans = s.substr(0, 1);
      cache.reserve(ceil(s.length() * s.length() / 0.75));
      for (int i = 0; i < s.length(); ++i) {
        for (int j = s.length() - 1; j >= i; --j) {
          int len = j - i + 1;
          if (work(s, i, j) && len > max_len) {
            max_len = len;
            ans = s.substr(i, len);
          }
        }
      }
      return ans;
    }

    bool work(string& s, int start, int end) {
      if ((it = cache.find(make(start, end))) != cache.end()) return it->second;
      if (start >= end) return true;
      bool ans = work(s, start + 1, end - 1) && s[start] == s[end];
      cache[make(start, end)] = ans;
      return ans;
    }
  };
}

TEST(dp_5, 4) {
  using namespace std;
  class Solution {
    pair<int, int> expand(string& s, int left, int right) {
      while (left >= 0 && right < s.length() && s[left] == s[right])
        left--, right++;
      return make_pair(left + 1, right - 1);
    }

   public:
    string longestPalindrome(string& s) {
      int start = 0, end = 0;
      for (int i = 0; i < s.length(); ++i) {
        auto [a, b] = expand(s, i, i);
        auto [c, d] = expand(s, i, i + 1);
        if (b - a > end - start) end = b, start = a;
        if (d - c > end - start) end = d, start = c;
      }
      return s.substr(start, end - start - 1);
    }
  };
}