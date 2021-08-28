//
// Created by XinShuo Wang on 2021/8/27 16:13
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_74, 1) {
  using namespace std;
  class Solution {
   public:
    void get(int idx, int col, int row, int& x, int& y) {
      x = idx / row;
      y = idx % row;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int col = matrix.size(), row = matrix[0].size();
      int left = 0, right = col * row - 1, mid = left + (right - left) / 2;
      int x, y;
      while (left < right) {
        get(mid, col, row, x, y);
        if (matrix[x][y] == target)
          return true;
        else if (matrix[x][y] < target)
          left = mid + 1;
        else
          right = mid - 1;
        mid = left + (right - left) / 2;
      }
      return matrix[x][y] == target;
    }
  };
}