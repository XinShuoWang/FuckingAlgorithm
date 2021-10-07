//
// Created by XinShuo Wang on 2021/10/6 10:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_03, 1) {
  using namespace std;
  class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {
      set<int> s;
      for (int num : nums) {
        if (s.find(num) == s.end()) s.insert(num);
        else return num;
      }
      return -1;
    }
  };
}


TEST(leetcode_jz_03, 2) {
  using namespace std;
  class Solution {
   public:
    int findRepeatNumber(vector<int>& nums) {

    }
  };
}