//
// Created by XinShuo Wang on 2021/12/30 13:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_846, 1) {
  using namespace std;
  class Solution {
    void sort(vector<int>& nums, int begin, int end) {
      if (begin >= end) return;
      int i = begin, j = end;
      while (i < j) {
        while (i < j && nums[j] >= nums[begin]) --j;
        while (i < j && nums[i] <= nums[begin]) ++i;
        if (i < j) swap(nums[i], nums[j]);
      }
      swap(nums[begin], nums[i]);
      this->sort(nums, begin, i - 1);
      this->sort(nums, i + 1, end);
    }

   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
      const int n = hand.size();
      // this->sort(hand, 0, n - 1);
      // std::sort(hand.begin(), hand.end(), [](int x, int y) { return x < y; });
      map<int, int> m;
      for (int i = 0; i < n; ++i) {
        if (m.find(hand[i]) == m.end())
          m[hand[i]] = 1;
        else
          m[hand[i]] += 1;
      }
      while (!m.empty()) {
        int flag = m.begin()->first;
        for (int i = 0; i < groupSize; ++i) {
          if (m.find(flag + i) == m.end()) {
            return false;
          } else {
            if (m[flag + i] == 1)
              m.erase(flag + i);
            else
              m[flag + i] -= 1;
          }
        }
      }
      return true;
    }
  };
}