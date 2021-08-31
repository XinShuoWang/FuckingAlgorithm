//
// Created by XinShuo Wang on 2021/8/31 9:43
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_713, 1) {
  using namespace std;
  class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if (k == 0) return 0;
      int ans = 0;
      for (int i = 0; i < nums.size(); ++i) {
        int v = nums[i];
        if (v < k) ans++;
        for (int j = i + 1; j < nums.size(); ++j) {
          v *= nums[j];
          if (v < k) {
            ans++;
          } else {
            break;
          }
        }
      }
      return ans;
    }
  };

  Solution solution;
  vector<int> v{10, 5, 2, 6};
  cout << solution.numSubarrayProductLessThanK(v, 100) << endl;
}

TEST(leetcode_713, 2) {
  using namespace std;
  class Solution {
    int work(int x, int y) { return (y - x) * (y - x + 1) / 2; }

   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if (k == 0) return 0;
      int ans = 0, v = nums[0], i, j;

      for (i = 0, j = 1; i < nums.size(); ++i) {
        if (i != 0) v /= nums[i - 1];
        int step = 0;
        for (; j < nums.size(); ++j) {
          v *= nums[j];
          step++;
          if (v >= k) break;
        }

        if (j == nums.size()) {
          if (v >= k) {
            // 这种情况是正好走到结束，然后超出范围
            ans += work(i, j);
          } else {
            // 这种情况是走到结束，没有超出范围
            ans += work(i, j + 1);
          }
          if (i != 0) ans -= work(i, j - step);
          return ans;
        } else {
          // 这里是超出范围了，但还没结束
          ans += work(i, j);
          if (i != 0) ans -= work(i, j - step);
          ++j;
        }
      }
      return ans;
    }
  };

  Solution solution;
  vector<int> v{10, 5, 2, 6};
  cout << solution.numSubarrayProductLessThanK(v, 100) << endl;
}