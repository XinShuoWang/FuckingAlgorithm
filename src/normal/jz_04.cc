//
// Created by XinShuo Wang on 2021/10/8 9:12
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_04, 1) {
  using namespace std;
  class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      for (vector<int>& v : matrix) {
        for (int num : v) {
          if (num == target) return true;
        }
      }
      return false;
    }
  };
}

TEST(leetcode_jz_04, 2) {
  using namespace std;
  class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      for (vector<int>& v : matrix) {
        if (v.size() == 0 || v[0] > target) break;
        if (target >= v.front() && target <= v.back()) {
          int left = 0, right = v.size();
          while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == target) {
              return true;
            } else if (target < v[mid]) {
              right = mid - 1;
            } else {
              left = mid + 1;
            }
          }
        }
      }
      return false;
    }
  };
}

TEST(leetcode_jz_04, 3) {
  using namespace std;
  class Solution {
   public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      if (matrix.empty()) return false;
      if (matrix[0].empty()) return false;
      int i = 0, j = matrix[0].size() - 1;
      while (j >= 0 && i < matrix.size()) {
        if (matrix[i][j] == target) {
          return true;
        } else if (matrix[i][j] < target) {
          ++i;
        } else {
          --j;
        }
      }
      return false;
    }
  };
}