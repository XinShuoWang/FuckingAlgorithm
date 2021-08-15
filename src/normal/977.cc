//
// Created by XinShuo Wang on 2021/8/15 12:40
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_977, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
      if (nums.size() == 1) return vector<int>{nums[0] * nums[0]};
      int index = absIncrement(nums);
      vector<int> res;
      if (index == -1) {
        for (int i = nums.size() - 1; i >= 0; --i) {
          res.push_back(nums[i] * nums[i]);
        }
        return res;
      } else {
        int left = index, right = index + 1;
        while (left >= 0 || right < nums.size()) {
          if (left >= 0 && right < nums.size()) {
            int v1 = nums[left] * nums[left];
            int v2 = nums[right] * nums[right];
            if (v1 == v2) {
              res.push_back(v1);
              left--;
            } else if (v1 > v2) {
              res.push_back(v2);
              right++;
            } else if (v1 < v2) {
              res.push_back(v1);
              left--;
            }
          } else if (left < 0 && right < nums.size()) {
            res.push_back(nums[right] * nums[right]);
            right++;
          } else if (left < 0 && right >= nums.size()) {
            return res;
          } else if (left >= 0 && right >= nums.size()) {
            res.push_back(nums[left] * nums[left]);
            left--;
          }
        }
        return res;
      }
    }

    int absIncrement(vector<int>& nums) {
      for (int i = 1; i < nums.size(); ++i) {
        if (abs(nums[i]) > abs(nums[i - 1])) return i - 1;
      }
      return -1;
    }
  };
}

TEST(leetcode_977, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      vector<int> res;
      while (left <= right) {
        int v1 = nums[left] * nums[left];
        int v2 = nums[right] * nums[right];
        if (v1 >= v2) {
          res.push_back(v1);
          left++;
        } else if (v1 < v2) {
          res.push_back(v2);
          right--;
        }
      }
      reverse(res.begin(), res.end());
      return res;
    }
  };
}