//
// Created by XinShuoWang on 2021/8/7.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_496, 1) {
  using namespace std;
  class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      // 1. 这一步先把单调栈处理完成
      vector<int> v(nums2.size(), -1);
      stack<int> s;
      // 想找后面比它大的，所以应该构造单调递减栈，这样栈里的元素才是“等待结果的”
      s.push(0);
      for (int i = 1; i < nums2.size(); ++i) {
        if (nums2[s.top()] == nums2[i]) {
          s.push(i);
        } else if (nums2[s.top()] < nums2[i]) {
          while (!s.empty() && nums2[s.top()] < nums2[i]) {
            // 这里面应该记录坐标
            v[s.top()] = i;
            s.pop();
          }
          s.push(i);
        } else {
          s.push(i);
        }
      }
      // 2. 这一步去找结果
      vector<int> res(nums1.size(), -1);
      for (int i = 0; i < nums1.size(); ++i) {
        for (int j = 0; j < nums2.size(); ++j) {
          if (nums1[i] == nums2[j]) {
            if (v[j] == -1) {
              res[i] = -1;
            } else {
              res[i] = nums2[v[j]];
            }
            break;
          }
        }
      }
      return res;
    }
  };
}

// 这一个使用MAP优化第二步的查找
TEST(others_496, 2) {
  using namespace std;
  class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      // 1. 这一步先把单调栈处理完成
      map<int, int> m;
      stack<int> s;
      // 想找后面比它大的，所以应该构造单调递减栈，这样栈里的元素才是“等待结果的”
      s.push(0);
      for (int i = 1; i < nums2.size(); ++i) {
        if (nums2[s.top()] == nums2[i]) {
          s.push(i);
        } else if (nums2[s.top()] < nums2[i]) {
          while (!s.empty() && nums2[s.top()] < nums2[i]) {
            // 这里面应该记录坐标
            m[nums2[s.top()]] = nums2[i];
            s.pop();
          }
          s.push(i);
        } else {
          s.push(i);
        }
      }
      // 2. 这一步去找结果
      vector<int> res(nums1.size(), -1);
      for (int i = 0; i < nums1.size(); ++i) {
        if (m.count(nums1[i]) == 0) {
          res[i] = -1;
        } else {
          res[i] = m[nums1[i]];
        }
      }
      return res;
    }
  };
}