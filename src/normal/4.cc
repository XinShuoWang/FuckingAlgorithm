//
// Created by XinShuo Wang on 2021/9/15 15:25
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_4, 1) {
  using namespace std;
  class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int len = nums1.size() + nums2.size();
      vector<int> v(len, 0);
      int m = 0, n = 0;
      for (int i = 0; i < len; ++i) {
        if (m >= nums1.size()) {
          v[i] = nums2[n++];
          continue;
        }
        if (n >= nums2.size()) {
          v[i] = nums1[m++];
          continue;
        }
        v[i] = nums1[m] < nums2[n] ? nums1[m++] : nums2[n++];
      }
      if (len % 2 == 0) {
        int pos = len / 2 - 1;
        return (v[pos] + v[pos + 1]) / 2.0;
      } else {
        int pos = len / 2;
        return v[pos];
      }
    }
  };
}