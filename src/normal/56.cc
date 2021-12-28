//
// Created by XinShuo Wang on 2021/12/26 20:50
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_46, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end(),
           [](vector<int>& x, vector<int>& y) { return x[0] < y[0]; });
      vector<vector<int>> ans;
      vector<int> t = intervals[0];
      for (int i = 1; i < intervals.size(); ++i) {
        if (t[1] >= intervals[i][0]) {
          t[1] = max(intervals[i][1], t[1]);
        } else {
          ans.push_back(t);
          t = intervals[i];
        }
      }
      ans.push_back(t);
      return ans;
    }
  };
}