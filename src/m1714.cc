//
// Created by XinShuo Wang on 2021/9/3 13:14
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_m1714, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
      priority_queue<int, vector<int>, greater<int>> q;
      for (int num : arr) {
        q.push(num);
      }
      vector<int> ans(k, 0);
      for (int i = 0; i < k; ++i) {
        ans[i] = q.top();
        q.pop();
      }
      return ans;
    }
  };
}


TEST(leetcode_m1714, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> smallestK(vector<int>& arr, int k) {
      priority_queue<int, vector<int>, greater<int>> q;
      for (int i = 0; i < k; ++i) {
        q.push(arr[i]);
      }
      for (int i = k; i < arr.size(); ++i) {
        // 把最大的弹出，让位给较小的元素
        if(q.top() > arr[i]){
          q.pop();
          q.push(arr[i]);
        }
      }
      vector<int> ans(k, 0);
      for (int i = 0; i < k; ++i) {
        ans[i] = q.top();
        q.pop();
      }
      return ans;
    }
  };
}