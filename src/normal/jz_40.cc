//
// Created by XinShuo Wang on 2021/10/20 10:16
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_40, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      vector<int> ans(k, 0);
      sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
      for (int i = 0; i < k; ++i) {
        ans[i] = arr[i];
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_40, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
      vector<int> ans(k, 0);
      if (k == 0) return ans;
      priority_queue<int, vector<int>, less<int>> q;
      for (int i = 0; i < k; ++i) {
        q.push(arr[i]);
      }
      for (int i = k; i < arr.size(); ++i) {
        if (q.top() > arr[i]) {
          q.pop();
          q.push(arr[i]);
        }
      }
      for (int i = 0; i < k; ++i) {
        ans[i] = q.top();
        q.pop();
      }
      return ans;
    }
  };
}