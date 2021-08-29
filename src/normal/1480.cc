//
// Created by XinShuo Wang on 2021/8/28 19:23
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1480, 1){
using namespace std;
  class Solution {
   public:
    vector<int> runningSum(vector<int>& nums) {
      vector<int> v(nums);
      for(int i = 1;i<v.size();++i){
        v[i] = v[i-1] + nums[i];
      }
      return v;
    }
  };
}