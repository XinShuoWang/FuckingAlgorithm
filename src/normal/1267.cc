//
// Created by XinShuoWang on 2021/8/10.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(disjoint_set_1267, 2) {
  using namespace std;
  class Solution {
    struct Node {
      int x;
      int y;
    };

   public:
    int countServers(vector<vector<int>>& grid) {
      vector<vector<Node>> nodes(grid.size(),
                                 vector<Node>(grid[0].size(), Node{}));
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          nodes[i][j].x = i;
          nodes[i][j].y = j;
        }
      }
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 1) {
            // 行，这里就从0开始，merge会保证是父节点之间进行合并
            for (int k = 0; k < grid[0].size(); ++k) {
              if (grid[i][k] == 1) this->merge(nodes, i, j, i, k);
            }
            // 列
            for (int k = 0; k < grid.size(); ++k) {
              if (grid[k][j] == 1) this->merge(nodes, i, j, k, j);
            }
            break;
          }
        }
      }

      return statistic(nodes, grid);
    }

    void merge(vector<vector<Node>>& nodes, int father_x, int father_y, int x,
               int y) {
      // 分别找到两个的父节点
      int a, b;
      this->find(nodes, father_x, father_y, a, b);
      int c, d;
      this->find(nodes, x, y, c, d);
      // 对父节点进行合并
      nodes[c][d].x = a;
      nodes[c][d].y = b;
    }

    void find(vector<vector<Node>>& nodes, int x, int y, int& father_x,
              int& father_y) {
      if (nodes[x][y].x == x && nodes[x][y].y == y) {
        father_x = x;
        father_y = y;
      } else {
        this->find(nodes, nodes[x][y].x, nodes[x][y].y, father_x, father_y);
        // 路径压缩
        nodes[x][y].x = father_x;
        nodes[x][y].y = father_y;
      }
    }

    int statistic(vector<vector<Node>>& nodes, vector<vector<int>>& grid) {
      int res = 0;
      set<pair<int, int>> fathers;
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 1 && (nodes[i][j].x != i || nodes[i][j].y != j)) {
            res++;
            int x, y;
            this->find(nodes, i, j, x, y);
            fathers.insert(pair<int, int>(x, y));
          }
        }
      }
      for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
          if (grid[i][j] == 1 && nodes[i][j].x == i && nodes[i][j].y == j &&
              fathers.count(pair<int, int>(i, j)) != 0) {
            res++;
          }
        }
      }
      return res;
    }
  };

  Solution solution;
  vector<vector<int>> t{{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  cout << solution.countServers(t) << endl;
}