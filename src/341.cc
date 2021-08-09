//
// Created by xinsh on 2021/7/31.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "NestedInteger.h"

TEST(tree_341, DFS) {
  using namespace std;
  class NestedIterator {
    vector<int> data;
    int pos;

   public:
    NestedIterator(vector<NestedInteger>& nestedList) {
      pos = 0;
      process(nestedList);
    }

    void process(const vector<NestedInteger>& nestedList) {
      // 这是递归的思路，二叉树的前序遍历是此种类型的特化：只有两个子节点
      for (NestedInteger integer : nestedList) {
        if (integer.isInteger())
          data.push_back(integer.getInteger());
        else
          process(integer.getList());
      }
    }

    int next() { return data[pos++]; }

    bool hasNext() { return pos < data.size(); }
  };
}

TEST(tree_341, stack) {
  using namespace std;
  class NestedIterator {
    queue<NestedInteger> q;

   public:
    NestedIterator(vector<NestedInteger>& nestedList) {
      for (NestedInteger integer : nestedList) {
        q.push(integer);
      }
    }

    int next() {}

    bool hasNext() { return !q.empty(); }
  };
}
