//
// Created by XinShuo Wang on 2021/9/9 9:14
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_155, 1) {
  using namespace std;
  class MinStack {
    priority_queue<int, vector<int>, greater<int>> q;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) { q.push(val); }

    void pop() { q.pop(); }

    int top() { return q.top(); }

    int getMin() { return q.top(); }
  };
}