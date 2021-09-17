//
// Created by XinShuo Wang on 2021/9/15 13:41
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_33, 1) {
  using namespace std;
  class Solution {
   public:
    int search(vector<int>& nums, int target) {
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) return i;
      }
      return -1;
    }
  };
}

TEST(leetcode_33, 2) {
  using namespace std;
  class Solution {
   public:
    int search(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (target == nums[mid]) return mid;
        if (nums[mid] > nums[left]) {
          if (target < nums[mid] && target >= nums[left]) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        } else {
          if (target > nums[mid] && target <= nums[right]) {
            left = mid + 1;
          } else {
            right = mid - 1;
          }
        }
      }
      return -1;
    }
  };

  Solution solution;
  vector<int> v{4, 5, 6, 7, 0, 1, 2};
  solution.search(v, 0);
}