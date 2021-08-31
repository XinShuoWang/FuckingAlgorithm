//
// Created by XinShuo Wang on 2021/8/29 15:49
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5855, 1) {
  using namespace std;
  class Solution {
    static bool cmp(string & a, string & b) {
      if (a.length() == b.length()) {
        for (int i = 0; i < a.length(); ++i) {
          if (a[i] == b[i])
            continue;
          else if (a[i] < b[i])
            return true;
          else
            return false;
        }
      } else if (a.length() > b.length()) {
        return false;
      } else if (a.length() < b.length()) {
        return true;
      }
      return false;
    }
   public:
    string kthLargestNumber(vector<string>& nums, int k) {
      sort(nums.begin(), nums.end(), cmp);
      // for(string& i : nums) cout << i << endl;
      return nums[nums.size() - k];
    }
  };
}