//
// Created by XinShuo Wang on 2021/10/23 10:02
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_33, 1) {
  using namespace std;
  class Solution {
   public:
    bool verifyPostorder(vector<int>& postorder) {
      return ok(postorder, 0, postorder.size() - 1);
    }

    bool ok(vector<int>& postorder, int start, int end) {
      if (start >= end) return true;
      int last = postorder[end], idx = start;
      while (postorder[idx] < last) idx++;
      int move = idx;
      while (move < end) {
        if (postorder[move] < last) return false;
        move++;
      }
      return ok(postorder, start, idx - 1) && ok(postorder, idx, end - 1);
    }
  };
}