//
// Created by XinShuo Wang on 2021/9/10 12:36
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_162, 1) {
  using namespace std;
  class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
      if (nums.size() == 1) return 0;
      if (nums[0] > nums[1]) return 0;
      if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
      for (int i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) return i;
      }
      return 0;
    }
  };
}

TEST(leetcode_162, 2) {
  using namespace std;
  class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
      /*
       * 1. 对于单调减数组来说，峰值在第一个元素
       * 2. 对于单调增元素来说，峰值在最后一个
       * 3. 对于凸形曲线或凹形曲线来说，曲线的一部分可以看成上面两种情况之一
       *
       * 类似单调栈思想：找到破坏单调性的元素就找到了题解
       * */
      for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i + 1]) return i;
      }
      return nums.size() - 1;
    }
  };
}

TEST(leetcode_162, 3) {
  using namespace std;
  class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
      int left = 0, right = nums.size() - 1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }
  };
}