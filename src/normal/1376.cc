//
// Created by XinShuoWang on 2021/8/9.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(tree_1376, DFS) {
  using namespace std;
  class Solution {
   private:
    bool flag;
    map<int, vector<int>> m;

   public:
    Solution() { flag = false; }

    void init(vector<int>& manager) {
      for (int i = 0; i < manager.size(); ++i) {
        if (m.count(manager[i]) == 0) {
          m[manager[i]] = vector<int>{i};
        } else {
          m[manager[i]].push_back(i);
        }
      }
    }

    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
      if (informTime[headID] == 0) return 0;
      if (!flag) {
        init(manager);
        flag = !flag;
      }
      int val = INT_MIN;
      for (int i : m[headID]) {
        val = max(val,
                  numOfMinutes(n, i, manager, informTime) + informTime[headID]);
      }
      return val;
    }
  };
}

TEST(tree_1376, 2) {
  using namespace std;
  class Solution {
   public:
    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
      if (informTime[headID] == 0) return 0;
      int val = INT_MIN;
      for (int i = 0; i < manager.size(); ++i) {
        if (manager[i] == headID) {
          int t = numOfMinutes(n, i, manager, informTime) + informTime[headID];
          val = val < t ? t : val;
        }
      }
      return val;
    }
  };
}