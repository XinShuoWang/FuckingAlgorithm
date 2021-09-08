//
// Created by XinShuo Wang on 2021/9/8 10:02
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_502, 1) {
  using namespace std;
  class Solution {
    int ans = INT_MIN;
    vector<bool> visited;

   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
      visited.resize(profits.size(), false);
      work(k, w, profits, capital);
      return ans == INT_MIN ? 0 : ans;
    }

    bool all_visited() {
      for (auto && i : visited) {
        if (!i) return false;
      }
      return true;
    }

    void work(int k, int w, vector<int>& profits, vector<int>& capital) {
      if (k == 0 || all_visited()) {
        ans = max(ans, w);
        return;
      }
      for (int i = 0; i < capital.size(); ++i) {
        if (!visited[i] && w >= capital[i]) {
          visited[i] = true;
          work(k - 1, w + profits[i], profits, capital);
          visited[i] = false;
        }
      }
    }
  };
}