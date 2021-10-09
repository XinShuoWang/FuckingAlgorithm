//
// Created by XinShuo Wang on 2021/10/9 9:34
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_10_2, 1) {
  using namespace std;
  class Solution {
   public:
    int numWays(int n) { return work(n, 0); }

    int work(int n, int s) {
      if (s == n) return 1;
      if (s > n) return 0;
      return work(n, s + 1) + work(n, s + 2);
    }
  };
}

TEST(leetcode_jz_10_2, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> m;
    unordered_map<int, int>::iterator it;

   public:
    int numWays(int n) {
      if (n == 0) return 1;
      if (n < 0) return 0;
      if ((it = m.find(n)) != m.end()) return it->second;
      int a = numWays(n - 1) % (int)(1e9 + 7);
      int b = numWays(n - 2) % (int)(1e9 + 7);
      int ans = (a + b) % (int)(1e9 + 7);
      m[n] = ans;
      return ans;
    }
  };
}