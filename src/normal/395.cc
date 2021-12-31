//
// Created by XinShuo Wang on 2021/12/30 10:25
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_395, 1) {
  using namespace std;
  class Solution {
   public:
    bool ok(array<array<int, 26>, 10001>& arr, int start, int end, int k) {
      for (int i = 0; i < 26; ++i) {
        int times = arr[end][i] - arr[start][i];
        if (times > 0 && times < k) return false;
      }
      return true;
    }

    int longestSubstring(string& s, int k) {
      const int n = s.length();
      array<array<int, 26>, 10001> count{};
      array<int, 26> arr{};
      for (int i = 0; i < n; ++i) {
        arr[s[i] - 'a']++;
        count[i + 1] = arr;
      }
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = i + k; j <= n; ++j) {
          if (ok(count, i, j, k)) ans = max(ans, j - i);
        }
      }
      return ans;
    }
  };
}