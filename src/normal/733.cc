//
// Created by XinShuo Wang on 2021/8/24 9:09
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_733, 1) {
  using namespace std;
  class Solution {
   public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
      queue<pair<int, int>> q;
      int oldColor = image[sr][sc];
      vector<vector<bool>> visited(image.size(),
                                   vector<bool>(image[0].size(), false));
      q.push(make_pair(sr, sc));
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (!visited[x][y]) {
          image[x][y] = newColor;
          visited[x][y] = true;
          if (x - 1 > -1 && image[x - 1][y] == oldColor)
            q.push(make_pair(x - 1, y));
          if (x + 1 < image.size() && image[x + 1][y] == oldColor)
            q.push(make_pair(x + 1, y));
          if (y - 1 > -1 && image[x][y - 1] == oldColor)
            q.push(make_pair(x, y - 1));
          if (y + 1 < image[0].size() && image[x][y + 1] == oldColor)
            q.push(make_pair(x, y + 1));
        }
      }
      return image;
    }
  };
}