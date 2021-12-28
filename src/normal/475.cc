//
// Created by XinShuo Wang on 2021/12/20 12:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_475, 1) {
  using namespace std;
  class Solution {
   public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
      const int m = houses.size(), n = heaters.size();
      vector<array<int, 2>> v(n, array<int, 2>{0, 0});
      for (int i = 0; i < n; ++i) {
        v[i][0] = heaters[i];
        v[i][1] = heaters[i];
      }
      int ans = 0;
      set<int> s(houses.begin(), houses.end());
      while (!s.empty()) {
        for (int i = 0; i < n; ++i) {
          v[i][0] -= 1;
          v[i][1] += 1;
          s.erase(v[i][0]);
          s.erase(v[i][1]);
        }
        ans++;
      }
      return ans;
    }
  };
}

TEST(leetcode_475, 2) {
  using namespace std;
  class Solution {
   public:
    int upper(vector<int>& heaters, int want) {
      return lower_bound(heaters.begin(), heaters.end(), want) -
             heaters.begin();
    }

    int lower(vector<int>& heaters, int want) {
      return upper(heaters, want) - 1;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
      int m = houses.size(), n = heaters.size(), ans = INT_MIN;
      sort(heaters.begin(), heaters.end(), [](int x, int y) { return x < y; });
      for (int i = 0; i < m; ++i) {
        int a = upper(heaters, houses[i]);
        int b = lower(heaters, houses[i]);
        int right = a >= n ? INT_MAX : heaters[a] - houses[i];
        int left = b < 0 ? INT_MAX : houses[i] - heaters[b];
        ans = max(ans, min(left, right));
      }
      return ans;
    }
  };
}