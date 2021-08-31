//
// Created by XinShuo Wang on 2021/8/30 9:20
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_11, 1) {
  using namespace std;
  class Solution {
   public:
    int maxArea(vector<int>& height) {
      int ans = INT_MIN;
      for (int i = 0; i < height.size(); ++i) {
        for (int j = i + 1; j < height.size(); ++j) {
          ans = max(ans, min(height[i], height[j]) * (j - i));
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_11, 2) {
  using namespace std;
  class Solution {
   public:
    int maxArea(vector<int>& height) {
      /* 主要思想：容量 = 两板距离 * 两板中最短高度
       * 如果移动长板，由于短板没变，两板距离还小了，所以容量一定变小
       * 如果移动短板，那么短板可能会变长，容量可能会变大
       * 所以每一次都选择有可能变大的选择
       *
       * 证明：用S(i,j)代表当前面积，假设height[i] < height[j]
       * 当由S(i,j)--->S(i+1,j)的时候，状态S(i,j-1),S(i,j-2),...,S(i,i+1)会被消除
       * 被消除的状态的高度是：min(height[i], height[j-1]),min(height[i], height[j-2]),...
       * 因此被消除的状态的高度(形如：min(height[i], height[j-1]))一定小于或等于height[i]
       * 而且宽度也会变窄，所以说去掉的状态面积一定都小于S(i,j)，所以最后一定能找到最大的
       */
      int ans = INT_MIN, i = 0, j = height.size() - 1;
      while (i < j) {
        int low = min(height[i], height[j]);
        ans = max(low * (j - i), ans);
        if (low == height[i]) {
          i++;
        } else {
          j--;
        }
      }
      return ans;
    }
  };
}