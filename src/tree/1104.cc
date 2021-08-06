//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "TreeNode.h"

TEST(tree_1104, 1) {
  using namespace std;
  class Solution {
   public:
    int work(int h, int l) {
      if (h % 2 == 0) {
        return (int)pow(2, h) - 1 - l;
      } else {
        return (int)pow(2, h - 1) + l;
      }
    }

    vector<int> pathInZigZagTree(int label) {
      if (label == 1) return vector<int>{1};
      int h;
      for (int i = 1; i < 1000; ++i) {
        if (label >= pow(2, i - 1) && label <= pow(2, i) - 1) {
          h = i;
          break;
        }
      }
      int l;
      if (h % 2 == 0) {
        // 15 - (14 - 8) - 8 = 15 - 6 - 8 = 1
        l = (int)pow(2, h) - 1 - label;
      } else {
        // 5 - 4 = 1
        l = label - (int)pow(2, h - 1);
      }
      vector<int> res;
      while (h > 0) {
        res.push_back(work(h, l));
        l /= 2;
        h--;
      }
      reverse(res.begin(), res.end());
      return res;
    }
  };
}