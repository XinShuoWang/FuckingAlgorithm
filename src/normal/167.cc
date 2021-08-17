//
// Created by XinShuo Wang on 2021/8/16 21:55
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_167, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      map<int, int> m;
      vector<int> v;
      for (int i = 0; i < numbers.size(); ++i) {
        if (m.count(target - numbers[i]) != 0) {
          v.push_back(m[target - numbers[i]]);
          v.push_back(i + 1);
          return v;
        }
        m[numbers[i]] = i + 1;
      }
      return v;
    }
  };
}

TEST(leetcode_167, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int i = 0, j = numbers.size() - 1;
      while (j >= 0 && i < numbers.size()) {
        int val = numbers[i] + numbers[j];
        if (val == target) return vector<int>{i + 1, j + 1};
        if (val < target) ++i;
        if (val > target) --j;
      }
      return vector<int>{0, 0};
    }
  };
}