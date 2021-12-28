//
// Created by XinShuo Wang on 2021/12/21 11:49
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_506, 1) {
  using namespace std;
  class Solution {
   public:
    string itoa(int val) {
      string ans;
      while (val != 0) {
        ans.push_back(val % 10);
        val /= 10;
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }

    vector<string> findRelativeRanks(vector<int>& score) {
      const int n = score.size();
      vector<int> v(score);
      sort(v.begin(), v.end(), [](int x, int y) { return x < y; });
      vector<string> ans(n);
      for (int i = 0; i < n; ++i) {
        int t = upper_bound(v.begin(), v.end(), score[i],
                            [](int x, int y) { return x < y; }) -
                v.begin();
        switch (t) {
          case 0:
            ans[i] = "Gold Medal";
            break;
          case 1:
            ans[i] = "Silver Medal";
            break;
          case 2:
            ans[i] = "Bronze Medal";
            break;
          default:
            ans[i] = itoa(t);
            break;
        }
      }
      return ans;
    }
  };
}