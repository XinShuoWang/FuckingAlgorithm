//
// Created by XinShuoWang on 2021/8/13.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_338, 1) {
  using namespace std;
  class Solution {
   public:
    int work(int num) {
      int res = 0;
      while (num > 0) {
        num = num & (num - 1);
        res++;
      }
      return res;
    }
    vector<int> countBits(int n) {
      vector<int> res(n + 1, 0);
      for (int i = 0; i <= n; ++i) {
        res[i] = work(i);
      }
      return res;
    }
  };
}

TEST(dp_338, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> countBits(int n) {
      switch (n) {
        case 0:
          return vector<int>{0};
        case 1:
          return vector<int>{0, 1};
        case 2:
          return vector<int>{0, 1, 1};
        case 3:
          return vector<int>{0, 1, 1, 2};
        default:
          vector<int> res(n + 1, 0);
          res[0] = 0;
          res[1] = 1;
          res[2] = 1;
          res[3] = 2;
          int t = 4, count = 0;
          for (int i = 4; i <= n; ++i) {
            res[i] = res[i - t] + 1;
            ++count;
            if (count == t) {
              count = 0;
              t *= 2;
            }
          }
          return res;
      }
    }
  };
}