//
// Created by XinShuo Wang on 2021/8/27 10:47
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_136, 1) {
  using namespace std;
  class Solution {
   public:
    int singleNumber(vector<int>& nums) {
      set<int> s;
      for (int& num : nums) {
        if (s.count(num) != 0)
          s.erase(num);
        else
          s.insert(num);
      }
      return *s.rbegin();
    }
  };
}

TEST(leetcode_136, 2) {
  using namespace std;
  class Solution {
   public:
    int singleNumber(vector<int>& nums) {
      int ans = 0;
      for (int num : nums) {
        ans ^= num;
      }
      return ans;
    }
  };
}