//
// Created by XinShuo Wang on 2021/10/4 13:40
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_09, 1) {
  using namespace std;
  class CQueue {
    stack<int> s1, s2;

   public:
    CQueue() {}

    void appendTail(int value) { s1.push(value); }

    int deleteHead() {
      int ans = -1;
      if (!s1.empty()) {
        while (s1.size() > 1) {
          s2.push(s1.top());
          s1.pop();
        }
        ans = s1.top();
        s1.pop();
        while (!s2.empty()) {
          s1.push(s2.top());
          s2.pop();
        }
      }
      return ans;
    }
  };
}

TEST(leetcode_jz_09, 2) {
  using namespace std;
  class CQueue {
    stack<int> s1, s2;

   public:
    CQueue() {}

    void appendTail(int value) { s1.push(value); }

    int deleteHead() {
      // s2中存放的是正确的队列，用top函数就可以取出
      // s1是倒序的队列，所以要进行反转再使用
      // 队列：1 2 3 4 5 6 7 8 9
      //          s2          s1
      //  栈： [1 2 3 4 5] [9 8 7 6]
      int ans = -1;
      if (!s2.empty()) {
        ans = s2.top();
        s2.pop();
        return ans;
      }
      if (s1.empty()) return ans;
      while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
      }
      ans = s2.top();
      s2.pop();
      return ans;
    }
  };
}