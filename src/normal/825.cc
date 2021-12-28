//
// Created by XinShuo Wang on 2021/12/27 13:25
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_825, 1) {
  using namespace std;
  class Solution {
   public:
    int numFriendRequests(vector<int>& ages) {
      int n = ages.size();
      int ans = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (i == j) continue;
          if (ages[j] <= 0.5 * ages[i] + 7 || ages[j] > ages[i] ||
              (ages[j] > 100 && ages[i] < 100)) {
            continue;
          } else {
            // cout << ages[i] << "->" << ages[j] << endl;
            ans++;
          }
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_825, 2) {
  using namespace std;
  class Solution {
   public:
    int numFriendRequests(vector<int>& ages) {
      int n = ages.size(), ans = 0;
      sort(ages.begin(), ages.end(), [](int x, int y) { return x < y; });
      for (int i = 0; i < n; ++i) {
        int a = 0.5 * ages[i] + 7, j = 0;
        while (j < n && ages[j] <= a) ++j;
        for (; j < n; ++j) {
          if (ages[j] > ages[i] || (ages[j] > 100 && ages[i] < 100)) break;
          if (i == j) continue;
          // cout << ages[i] << "->" << ages[j] << endl;
          ans++;
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_825, 3) {
  using namespace std;
  class Solution {
   public:
    // 大于
    int upper(vector<int>& ages, int want) {
      auto ans = upper_bound(ages.begin(), ages.end(), want);
      if(ans == ages.end()) return ages.size();
      else return ans - ages.begin();
    }

    // 小于等于
    int lower(vector<int>& ages, int want) {
      return lower_bound(ages.begin(), ages.end(), want) - ages.begin();
    }

    int numFriendRequests(vector<int>& ages) {
      int n = ages.size(), ans = 0;
      sort(ages.begin(), ages.end(), [](int x, int y) { return x < y; });
      for (int i = 0; i < n; ++i) {
        int threshold = 0.5 * ages[i] + 7;
        int a = upper(ages, threshold);
        int b = lower(ages, ages[i]);
        if (a < b) ans += (b - a - 1);
      }
      return ans;
    }
  };
}