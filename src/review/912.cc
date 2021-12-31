//
// Created by XinShuo Wang on 2021/12/29 13:54
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_912, 1) {
  using namespace std;
  class Solution {
   public:
    void work1(vector<int>& nums, int start, int end) {
      if (start >= end) return;
      int i = start, j = end;
      while (i < j) {
        // 以start为标志时，要j先走
        while (i < j && nums[j] >= nums[start]) --j;
        while (i < j && nums[i] <= nums[start]) ++i;
        if (i < j) swap(nums[i], nums[j]);
      }
      // 下面的是i或者j都可以
      swap(nums[i], nums[start]);
      work1(nums, start, i - 1);
      work1(nums, i + 1, end);
    }

    void work2(vector<int>& nums, int start, int end) {
      if (start >= end) return;
      int i = start, j = end;
      while (i < j) {
        // 以end为标志时，要i先走
        while (i < j && nums[i] <= nums[end]) ++i;
        while (i < j && nums[j] >= nums[end]) --j;
        if (i < j) swap(nums[i], nums[j]);
      }
      // 下面的是i或者j都可以
      swap(nums[i], nums[end]);
      work2(nums, start, i - 1);
      work2(nums, i + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
      work1(nums, 0, nums.size() - 1);
      return nums;
    }
  };
}

TEST(leetcode_912, 2) {
  using namespace std;
  class Solution {
    int partition(vector<int>& nums, int l, int r) {
      int pivot = nums[r];
      int i = l - 1;
      for (int j = l; j <= r - 1; ++j) {
        if (nums[j] <= pivot) {
          i = i + 1;
          swap(nums[i], nums[j]);
        }
      }
      swap(nums[i + 1], nums[r]);
      return i + 1;
    }

    int randomized_partition(vector<int>& nums, int l, int r) {
      int i = rand() % (r - l + 1) + l;  // 随机选一个作为我们的主元
      swap(nums[r], nums[i]);
      return partition(nums, l, r);
    }

    void randomized_quicksort(vector<int>& nums, int l, int r) {
      if (l < r) {
        int pos = randomized_partition(nums, l, r);
        randomized_quicksort(nums, l, pos - 1);
        randomized_quicksort(nums, pos + 1, r);
      }
    }

   public:
    vector<int> sortArray(vector<int>& nums) {
      srand((unsigned)time(NULL));
      randomized_quicksort(nums, 0, (int)nums.size() - 1);
      return nums;
    }
  };
}