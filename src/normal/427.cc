//
// Created by XinShuo Wang on 2021/9/28 9:19
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_427, 1) {
  using namespace std;
  // Definition for a QuadTree node.
  class Node {
   public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
      val = false;
      isLeaf = false;
      topLeft = NULL;
      topRight = NULL;
      bottomLeft = NULL;
      bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
      val = _val;
      isLeaf = _isLeaf;
      topLeft = NULL;
      topRight = NULL;
      bottomLeft = NULL;
      bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight,
         Node* _bottomLeft, Node* _bottomRight) {
      val = _val;
      isLeaf = _isLeaf;
      topLeft = _topLeft;
      topRight = _topRight;
      bottomLeft = _bottomLeft;
      bottomRight = _bottomRight;
    }
  };
  class Solution {
   public:
    Node* construct(vector<vector<int>>& grid) {
      return work(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }

    bool ok(vector<vector<int>>& grid, int start_x, int end_x, int start_y,
            int end_y) {
      int ans = grid[start_x][start_y];
      for (int i = start_x; i <= end_x; ++i) {
        for (int j = start_y; j <= end_y; ++j) {
          if (grid[i][j] != ans) return false;
        }
      }
      return true;
    }

    Node* work(vector<vector<int>>& grid, int start_x, int end_x, int start_y,
               int end_y) {
      if (ok(grid, start_x, end_x, start_y, end_y)) {
        // 叶子结点
        return new Node(grid[start_x][start_y], true, nullptr, nullptr, nullptr,
                        nullptr);
      } else {
        // 非叶子结点
        Node* ans = new Node();
        ans->isLeaf = false;
        ans->topLeft = work(grid,
                            start_x, (end_x - start_x) / 2 + start_x,
                            start_y, (end_y - start_y) / 2 + start_y);
        ans->topRight = work(grid,
                             start_x, (end_x - start_x) / 2 + start_x,
                             (end_y - start_y) / 2 + start_y + 1, end_y);
        ans->bottomLeft = work(grid,
                               (end_x - start_x) / 2 + start_x + 1, end_x,
                               start_y, (end_y - start_y) / 2 + start_y);
        ans->bottomRight =
            work(grid,
                 (end_x - start_x) / 2 + start_x + 1, end_x,
                 (end_y - start_y) / 2 + start_y + 1, end_y);
        return ans;
      }
    }
  };

  vector<vector<int>> v{{1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1, 1, 1},
                        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0},
                        {1, 1, 1, 1, 0, 0, 0, 0}, {1, 1, 1, 1, 0, 0, 0, 0}};
  Solution solution;
  solution.construct(v);
}