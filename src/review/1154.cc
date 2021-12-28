//
// Created by XinShuo Wang on 2021/12/21 11:41
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1154, 1) {
  using namespace std;
  class Solution {
   public:
    int dayOfYear(string date) {
      int year = stoi(date.substr(0, 4));
      int month = stoi(date.substr(5, 2));
      int day = stoi(date.substr(8, 2));

      int amount[] = {31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};
      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        ++amount[1];
      }

      int ans = 0;
      for (int i = 0; i < month - 1; ++i) {
        ans += amount[i];
      }
      return ans + day;
    }
  };
}