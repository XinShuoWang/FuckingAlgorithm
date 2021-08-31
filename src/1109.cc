//
// Created by XinShuo Wang on 2021/8/31 18:27
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1109, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> ans(n, 0);
      for (int i = 0; i < bookings.size(); ++i) {
        int start = bookings[i][0], end = bookings[i][1], num = bookings[i][2];
        for (int j = start; j <= end; ++j) {
          ans[j - 1] += num;
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_1109, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
      vector<int> ans(n + 1, 0);
      for (int i = 0; i < bookings.size(); ++i) {
        ans[bookings[i][0] - 1] += bookings[i][2];
        // 给1到2加10，那么第3个仍未0
        ans[bookings[i][1]] -= bookings[i][2];
      }
      // 对差分数组求前缀和
      for (int i = 1; i < ans.size(); ++i) {
        ans[i] = ans[i] + ans[i - 1];
      }
      ans.erase(ans.begin() + n);
      return ans;
    }
  };
}