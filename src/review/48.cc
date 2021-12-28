//
// Created by XinShuo Wang on 2021/12/24 14:42
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_48, 1) {
  using namespace std;
  class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int a, b, c, d, t;
      for (int i = 0; i < m / 2; ++i) {
        for (int j = i; j < m - i; ++j) {
          a = matrix[i][j], b = matrix[j][m - i];
          c = matrix[m - i][m - j], d = matrix[j][m - j];
          t = a, a = b, b = c, c = d, d = t;
        }
      }
    }
  };
}