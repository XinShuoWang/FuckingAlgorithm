//
// Created by XinShuo Wang on 2021/9/16 9:55
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_343, 1) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int integerBreak(int n) { return work(n, true); }

    int work(int n, bool first) {
      if (n == 0) return 1;
      if (n < 0) return -1;
      if ((it = cache.find(n)) != cache.end()) return it->second;
      int ans = 1;
      for (int i = 1; i < (first ? n : n + 1); ++i) {
        ans = max(ans, i * work(n - i, false));
      }
      cache[n] = ans;
      return ans;
    }
  };

  Solution solution;
  solution.integerBreak(2);
}