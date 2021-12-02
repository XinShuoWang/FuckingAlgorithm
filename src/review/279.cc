//
// Created by XinShuo Wang on 2021/12/2 16:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_279, 1) {
  using namespace std;
  class Solution {
    array<int, 100> arr;
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    Solution() {
      arr = {10000, 9801, 9604, 9409, 9216, 9025, 8836, 8649, 8464, 8281,
             8100,  7921, 7744, 7569, 7396, 7225, 7056, 6889, 6724, 6561,
             6400,  6241, 6084, 5929, 5776, 5625, 5476, 5329, 5184, 5041,
             4900,  4761, 4624, 4489, 4356, 4225, 4096, 3969, 3844, 3721,
             3600,  3481, 3364, 3249, 3136, 3025, 2916, 2809, 2704, 2601,
             2500,  2401, 2304, 2209, 2116, 2025, 1936, 1849, 1764, 1681,
             1600,  1521, 1444, 1369, 1296, 1225, 1156, 1089, 1024, 961,
             900,   841,  784,  729,  676,  625,  576,  529,  484,  441,
             400,   361,  324,  289,  256,  225,  196,  169,  144,  121,
             100,   81,   64,   49,   36,   25,   16,   9,    4,    1};
    }

    int combine(int n, int step) {
      int ans = n;
      ans <<= 16;
      ans += step;
      return ans;
    }

    int dfs(int n, int step) {
      if (n == 0) return 0;
      if (step >= 100) return INT_MAX / 2;
      if ((it = cache.find(combine(n, step))) != cache.end()) return it->second;
      int ans = INT_MAX / 2;
      for (int i = 0; i <= n / arr[step]; ++i) {
        ans = min(ans, dfs(n - arr[step] * i, step + 1) + i);
      }
      cache[combine(n, step)] = ans;
      return ans;
    }

    int numSquares(int n) { return dfs(n, 0); }
  };
}

TEST(leetcode_279, 2) {
  using namespace std;
  class Solution {
    array<int, 100> arr = {
        10000, 9801, 9604, 9409, 9216, 9025, 8836, 8649, 8464, 8281, 8100, 7921,
        7744,  7569, 7396, 7225, 7056, 6889, 6724, 6561, 6400, 6241, 6084, 5929,
        5776,  5625, 5476, 5329, 5184, 5041, 4900, 4761, 4624, 4489, 4356, 4225,
        4096,  3969, 3844, 3721, 3600, 3481, 3364, 3249, 3136, 3025, 2916, 2809,
        2704,  2601, 2500, 2401, 2304, 2209, 2116, 2025, 1936, 1849, 1764, 1681,
        1600,  1521, 1444, 1369, 1296, 1225, 1156, 1089, 1024, 961,  900,  841,
        784,   729,  676,  625,  576,  529,  484,  441,  400,  361,  324,  289,
        256,   225,  196,  169,  144,  121,  100,  81,   64,   49,   36,   25,
        16,    9,    4,    1};

   public:
    int numSquares(int n) {
      queue<int> q;
      for (int num : arr) {
        if (num <= n) q.push(num);
      }
      int level = 1;
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          if (q.front() == n) return level;
          for (int num : arr) {
            if (q.front() + num < n)
              q.push(q.front() + num);
            else if (q.front() + num == n)
              return level + 1;
          }
          size--;
          q.pop();
        }
        level++;
      }
      return 0;
    }
  };
}