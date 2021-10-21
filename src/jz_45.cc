//
// Created by XinShuo Wang on 2021/10/21 13:12
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include <cstdlib>
#include <cstdio>

TEST(leetcode_jz_45, 1){
using namespace std;
  class Solution {
   public:
    string minNumber(vector<int>& nums) {
      vector<string> v(nums.size());
      for (int num : nums) {
        v.emplace_back(itoa(num));
      }
      return "";
    }
  };
}