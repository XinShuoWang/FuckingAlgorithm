//
// Created by XinShuo Wang on 2021/9/29 9:18
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_746, 1) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

   public:
    int minCostClimbingStairs(vector<int>& cost) {
      return min(work(cost, 0), work(cost, 1));
    }

    int work(vector<int>& cost, int step) {
      if (step >= cost.size()) return 0;
      if ((it = cache.find(step)) != cache.end()) return it->second;
      int a = work(cost, step + 1);
      int b = work(cost, step + 2);
      int ans = cost[step] + min(a, b);
      cache[step] = ans;
      return ans;
    }
  };
}

TEST(leetcode_746, 2) {
  using namespace std;
  class Solution {
    int ans;

   public:
    Solution() { ans = INT_MAX; }

    int minCostClimbingStairs(vector<int>& cost) {
      work(cost, 0, 0);
      work(cost, 1, 0);
      return ans;
    }

    void work(vector<int>& cost, int step, int val) {
      if (step >= cost.size()) {
        ans = min(ans, val);
        return;
      }
      work(cost, step + 1, val + cost[step]);
      work(cost, step + 2, val + cost[step]);
    }
  };
}