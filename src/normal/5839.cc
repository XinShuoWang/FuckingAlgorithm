//
// Created by XinShuoWang on 2021/8/8.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_5839, 1) {
  using namespace std;
  class Solution {
   public:
    // 这个实现是超时的
    int minStoneSum(vector<int>& piles, int k) {
      if (k == 0) return accumulate(piles.begin(), piles.end(), 0);
      auto v = max_element(piles.begin(), piles.end());
      *v -= *v / 2;
      return minStoneSum(piles, k - 1);
    }
  };
}

TEST(others_5839, 2) {
  using namespace std;
  class Solution {
   public:
    // 这个实现使用了优先队列，优先队列的底层实现是堆
    int minStoneSum(vector<int>& piles, int k) {
      priority_queue<int, vector<int>, less<int>> q;
      int sum = 0;
      for (int i = 0; i < piles.size(); ++i) {
        q.push(piles[i]);
        sum += piles[i];
      }
      while (k > 0) {
        int v = q.top();
        sum -= v / 2;
        q.pop();
        q.push(v - v / 2);
        k--;
      }
      return sum;
    }
  };
}