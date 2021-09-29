//
// Created by XinShuo Wang on 2021/9/24 10:28
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

// Floyd算法
TEST(leetcode_743, 1) {
  using namespace std;
  class Solution {
   public:
    // BFS行不通，因为边有权值
    // 需要使用最短路算法
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      // 初始化邻接矩阵
      vector<vector<int>> dist(n + 1, vector<int>(n + 1, 0x3f3f3f));
      for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
      }
      for (vector<int>& v : times) {
        int start = v[0], end = v[1], weight = v[2];
        dist[start][end] = weight;
      }
      // Floyd算法
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          for (int l = 1; l <= n; ++l) {
            dist[j][l] = min(dist[j][l], dist[j][i] + dist[i][l]);
          }
        }
      }
      int ans = 0;
      // 起始点已经固定为K
      for (int i = 1; i <= n; ++i) {
        ans = max(ans, dist[k][i]);
      }
      return ans >= 0x3f3f3f / 2 ? -1 : ans;
    }
  };
}

// Bellman-Ford算法
TEST(leetcode_743, 2) {
  using namespace std;
  class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      const int maximum = 0x3f3f3f;
      vector<int> distance(n + 1, maximum);
      distance[k] = 0;
      for (int i = 1; i <= n; ++i) {
        for (auto& time : times) {
          int start = time[0], end = time[1], weight = time[2];
          // 松弛操作就相当于考察能否经由start点使起点到end点的距离变短。
          distance[end] = min(distance[end], distance[start] + weight);
        }
      }
      int ans = 0;
      for (int i = 1; i <= n; ++i) {
        ans = max(ans, distance[i]);
      }
      return ans == maximum ? -1 : ans;
    }
  };
}