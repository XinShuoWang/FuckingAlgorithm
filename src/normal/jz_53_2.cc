//
// Created by XinShuo Wang on 2021/10/6 10:29
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_53_2, 1) {
  using namespace std;
  class Solution {
   public:
    int missingNumber(vector<int>& nums) {
      unordered_set<int> s;
      for (int i = 0; i <= nums.size(); ++i) s.insert(i);
      for (int num : nums) s.erase(num);
      return *s.begin();
    }
  };
}

TEST(leetcode_jz_53_2, 2) {
  using namespace std;
  class Solution {
   public:
    int missingNumber(vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i)
        if (nums[i] != i) return i;
      return nums.size();
    }
  };
}

TEST(leetcode_jz_53_2, 3) {
  using namespace std;
  class Solution {
   public:
    int missingNumber(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] != mid) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }
  };
}