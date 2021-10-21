//
// Created by XinShuo Wang on 2021/10/20 9:59
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_13, 1) {
  using namespace std;
  class Solution {
    bool ok(int i, int j, int k) {
      int ans = 0;
      while (i != 0) {
        ans += i % 10;
        i /= 10;
      }
      while (j != 0) {
        ans += j % 10;
        j /= 10;
      }
      return ans <= k;
    }

   public:
    int movingCount(int m, int n, int k) {
      queue<pair<int, int>> q;
      q.push(make_pair(0, 0));
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      visited[0][0] = true;
      int ans = 1;
      while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x - 1 >= 0 && !visited[x - 1][y] && ok(x - 1, y, k)) {
          visited[x - 1][y] = true;
          q.push(make_pair(x - 1, y));
          ans++;
        }
        if (x + 1 < m && !visited[x + 1][y] && ok(x + 1, y, k)) {
          visited[x + 1][y] = true;
          q.push(make_pair(x + 1, y));
          ans++;
        }
        if (y - 1 >= 0 && !visited[x][y - 1] && ok(x, y - 1, k)) {
          visited[x][y - 1] = true;
          q.push(make_pair(x, y - 1));
          ans++;
        }
        if (y + 1 < n && !visited[x][y + 1] && ok(x, y + 1, k)) {
          visited[x][y + 1] = true;
          q.push(make_pair(x, y + 1));
          ans++;
        }
      }
      return ans;
    }
  };
}