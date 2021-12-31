//
// Created by XinShuo Wang on 2021/12/31 11:42
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_507, 1){
  using namespace std;
  class Solution {
   public:
    bool checkPerfectNumber(int num) {
      if(num == 1) return false;
      int sum = 0, end = sqrt(num);
      for(int i = 2; i <= end; ++i) {
        if(num % i == 0) {
          // cout << i << "," << num / i << endl;
          sum += (i + num / i);
        }
      }
      return sum + 1 == num;
    }
  };
} 