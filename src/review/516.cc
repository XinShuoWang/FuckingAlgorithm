//
// Created by XinShuo Wang on 2021/12/2 15:31
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_516, 1) {
  using namespace std;
  class Solution {
    string path;
    int ans;

   public:
    Solution() {
      path.reserve(1005);
      ans = 0;
    }

    bool ok() {
      if (path.empty()) return true;
      if (path.length() == 1) return true;
      int left = 0, right = path.length() - 1;
      while (left < right) {
        if (path[left] != path[right]) return false;
        left++, right--;
      }
      return true;
    }

    void dfs(string& s, int step) {
      if (step >= s.length()) {
        if (path.length() > ans && ok()) ans = path.length();
        return;
      }
      path.push_back(s[step]);
      dfs(s, step + 1);
      path.pop_back();
      dfs(s, step + 1);
    }

    int longestPalindromeSubseq(string& s) {
      dfs(s, 0);
      return ans;
    }
  };
}

TEST(leetcode_516, 2) {
  using namespace std;
  class Solution {
   public:
    int longestPalindromeSubseq(string& s) {
      int n = s.length();
      vector<vector<int>> dp(n, vector<int>(n));
      for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i + 1][j - 1] + 2;
          } else {
            // 这时候(i,j)是肯定不行的了，所以就看看(i+1, j)或者(i,j-1)行不行
            // (i+1,j)也不一定保证就选j，(i,j-1)也不一定保证就选i
            // 只是选择他们俩中谁构造出的子序列比较长而已
            // 最终的递归终止条件就是单个字符
            dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
          }
        }
      }
      return dp[0][n - 1];
    }
  };
}