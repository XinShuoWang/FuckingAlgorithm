//
// Created by XinShuoWang on 2021/8/6.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_322, DFS) {
  using namespace std;
  class Solution {
    // 这里不仅要缓存可以换成的，还要记录不可以换成的
    unordered_map<int, int> cache_;

   public:
    int coinChange(vector<int>& coins, int amount) {
      if (amount == 0) return 0;
      return work(coins, amount);
    }

    int work(vector<int>& coins, int amount) {
      if(cache_.find(amount) != cache_.end()) return cache_[amount];
      if (amount < 0) return -1;
      for (int coin : coins) {
        if (amount == coin) return 1;
      }
      int res = INT_MAX;
      for (int coin : coins) {
        int t = coinChange(coins, amount - coin);
        if (t != -1) res = min(1 + t, res);
      }
      cache_[amount] = res == INT_MAX ? -1 : res;
      return res == INT_MAX ? -1 : res;
    }
  };
}