//
// Created by XinShuo Wang on 2022/1/10 13:37
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_306, 1) {
  using namespace std;
  class Solution {
   public:
    static string add(string& a, string& b) {
      int i = a.length() - 1, j = b.length() - 1, p = 0;
      string ans;
      while (i >= 0 || j >= 0) {
        int x = (i >= 0 ? a[i] : '0') - '0';
        int y = (j >= 0 ? b[j] : '0') - '0';
        int z = x + y + p;
        p = z / 10, z %= 10;
        ans.push_back((char)('0' + z));
        --i, --j;
      }
      if (p != 0) ans.push_back((char)('0' + p));
      reverse(ans.begin(), ans.end());
      return ans;
    }

    bool dfs(string& num, int start_x, int len_x, int len_y) {
      if (start_x >= num.length()) return true;
      string x = num.substr(start_x, len_x),
             y = num.substr(start_x + len_x, len_y), ans = add(x, y);
      if ((x != "0" && x[0] == '0') || (y != "0" && y[0] == '0')) return false;
      // cout << x << "+" << y << "=" << ans << endl;
      int len = num.length() - (start_x + len_x + len_y);
      if (ans.length() > len) return false;
      if (memcmp(ans.c_str(), num.c_str() + start_x + len_x + len_y,
                 ans.length()) != 0) {
        return false;
      } else {
        if (ans.length() == len) return true;
        for (int i = 1; i <= len / 2; ++i) {
          for (int j = 1; j <= len / 2; ++j) {
            if (dfs(num, start_x + len_x, i, j)) return true;
          }
        }
        return false;
      }
    }

    bool isAdditiveNumber(string& num) {
      if (num.size() < 3) return false;
      int n = num.length();
      for (int i = 1; i <= n / 2; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
          if (dfs(num, 0, i, j)) return true;
        }
      }
      return false;
    }
  };
}