//
// Created by xinsh on 2021/8/4.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_152, 1) {
  using namespace std;
  class Solution {
   public:
    int maxProduct(vector<int>& nums) {
      int max = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        int t = nums[i];
        max = max < t ? t : max;
        for (int j = i + 1; j < nums.size(); ++j) {
          t *= nums[j];
          max = max < t ? t : max;
        }
      }
      return max;
    }
  };
}

TEST(dp_152, 2) {
  using namespace std;
  class Solution {
   public:
    int maxProduct(vector<int>& nums) {
      int ans = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        int t = nums[i];
        ans = max(t, ans);
        for (int j = i + 1; j < nums.size(); ++j) {
          t *= nums[j];
          ans = max(ans, t);
        }
      }
      return ans;
    }
  };
}

TEST(dp_152, 3) {
  using namespace std;
  class Solution {
   public:
    int maxProduct(vector<int>& nums) {
      int imax = 1, imin = 1, ans = INT_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0) {
          int t = imax;
          imax = imin;
          imin = t;
        }
        imax = max(imax * nums[i], nums[i]);
        imin = min(imin * nums[i], nums[i]);
        ans = max(ans, imax);
      }
      return ans;
    }
  };
}
