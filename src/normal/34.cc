//
// Created by XinShuo Wang on 2021/8/27 17:05
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_34, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
      auto pos = find(nums.begin(), nums.end(), target);
      if (pos == nums.end()) return vector<int>{-1, -1};
      int x = pos - nums.begin(), y = x + 1;
      while (y < nums.size() && nums[y] == nums[x]) y++;
      return vector<int>{x, y - 1};
    }
  };
}

TEST(leetcode_34, 2) {
  using namespace std;
  class Solution {
   public:
    int find(vector<int>& nums, int target) {
      int left = 0, right = nums.size() - 1, mid = left + (right - left) / 2;
      while (left < right) {
        if (nums[mid] == target)
          return mid;
        else if (nums[mid] < target)
          left = mid + 1;
        else
          right = mid - 1;
        mid = left + (right - left) / 2;
      }
      return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
      if (nums.size() == 0) return vector<int>{-1, -1};
      int pos = find(nums, target);
      if (nums[pos] == target) {
        int left = pos - 1, right = pos + 1;
        while (left >= 0 && nums[left] == target) left--;
        while (right < nums.size() && nums[right] == target) right++;
        return vector<int>{left + 1, right - 1};
      }
      return vector<int>{-1, -1};
    }
  };
}