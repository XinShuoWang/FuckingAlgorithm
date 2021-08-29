//
// Created by XinShuo Wang on 2021/8/28 14:55
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_P3372, 1) {
  using namespace std;
  class SegmentTree {
   private:
    struct Node {
      int left;
      int right;
      int sum;
      int lazy;
      Node() { left = right = sum = lazy = 0; }
    };

    int data[1000];
    Node nodes[4 * 1000];

   public:
    // 这里的left和right是区间的起始与结束
    void build(int idx, int left, int right) {
      nodes[idx].left = left;
      nodes[idx].right = right;
      if (left == right) {
        // 这里到达叶子结点，需要赋值
        nodes[idx].sum = data[idx];
      } else {
        int mid = left + (right - left) / 2;
        build(idx << 1, left, mid);
        build(idx << 1 | 1, mid + 1, right);
        nodes[idx].sum = nodes[idx << 1].sum + nodes[idx << 1 | 1].sum;
      }
    }

    void down(int idx) {
      int left = idx << 1, right = idx << 1 | 1;
      nodes[left].lazy += nodes[idx].lazy;
      nodes[left].sum +=
          (nodes[left].right - nodes[left].left + 1) * nodes[idx].lazy;
      nodes[right].lazy += nodes[idx].lazy;
      nodes[right].sum +=
          (nodes[right].right - nodes[right].left + 1) * nodes[idx].lazy;
      nodes[idx].lazy = 0;
    }

    void update(int idx, int left, int right, int value) {
      if (idx < left || idx > right) return;
      if (idx <= right && idx >= left) {
        nodes[idx].lazy = value;
        nodes[idx].sum += value * (nodes[idx].right - nodes[idx].left);
      } else {
        if (nodes[idx].lazy > 0) down(idx);
        update(idx << 1, left, right, value);
        update(idx << 1 | 1, left, right, value);
        nodes[idx].sum = nodes[idx << 1].sum + nodes[idx << 1 | 1].sum;
      }
    }

    int query(int idx, int left, int right) {
      if (idx < left || idx > right) return 0;
      if (idx >= left && idx <= right) return nodes[idx].sum;
      if (nodes[idx].lazy > 0) down(idx);
      return query(idx << 1, left, right) + query(idx << 1 | 1, left, right);
    }
  };
}