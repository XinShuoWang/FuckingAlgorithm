//
// Created by XinShuo Wang on 2021/10/8 9:45
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_11, 1) {
  using namespace std;
  class Solution {
   public:
    int minArray(vector<int>& numbers) {
      return *min_element(numbers.begin(), numbers.end());
    }
  };
}

TEST(leetcode_jz_11, 2) {
  using namespace std;
  class Solution {
   public:
    int minArray(vector<int>& numbers) {
      int i = 0, j = numbers.size() - 1;
      while (i < j) {
        int m = (i + j) / 2;
        if (numbers[m] > numbers[j])
          i = m + 1;
        else if (numbers[m] < numbers[j])
          j = m;
        else
          j--;
      }
      return numbers[i];
    }
  };
}