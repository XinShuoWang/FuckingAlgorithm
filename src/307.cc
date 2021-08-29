//
// Created by XinShuo Wang on 2021/8/28 20:48
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_307, 1) {
  using namespace std;

  class SegmentTree {
   private:
    struct Node {
      int left;
      int right;
      int sum;
      Node() { left = right = sum = 0; }
    };
    vector<int> data;
    Node nodes[4 * 3 * 10000];

   public:
    SegmentTree(vector<int>& nums) { data = nums; }

    void build(int idx, int left, int right) {
      nodes[idx].left = left;
      nodes[idx].right = right;
      if (left == right) {
        nodes[idx].sum = data[left];
      } else {
        int mid = (left + right) / 2;
        build(idx << 1, left, mid);
        build(idx << 1 | 1, mid + 1, right);
      }
    }

    void update(int idx, int left, int right, int value) {
      if (left == right) {
        if (idx == left) {
          nodes[idx].sum = value;
        } else {
          return;
        }
      } else {
        int mid = (left + right) / 2;
        update(idx << 1, left, mid, value);
        update(idx << 1 | 1, mid + 1, right, value);
        nodes[idx].sum = nodes[idx << 1].sum + nodes[idx << 1 | 1].sum;
      }
    }

    int query(int idx, int left, int right) {
      if (nodes[idx].left > right || nodes[idx].right < left) {
        return INT_MIN;
      }
      if (nodes[idx].left == left && nodes[idx].right == right) {
        return nodes[idx].sum;
      } else {
        int mid = (left + right) / 2;
        int a = query(idx << 1, left, mid);
        int b = query(idx << 1 | 1, mid + 1, right);
        return a == INT_MIN ? b : a;
      }
    }
  };

  class NumArray {
    SegmentTree* tree;
    int size;

   public:
    NumArray(vector<int>& nums) {
      tree = new SegmentTree(nums);
      tree->build(1, 1, nums.size());
      size = nums.size();
    }

    void update(int index, int val) { tree->update(1, 1, size, val); }

    int sumRange(int left, int right) { return tree->query(1, left, right); }
  };
}