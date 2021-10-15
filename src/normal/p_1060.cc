//
// Created by XinShuo Wang on 2021/10/10 16:37
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_p_1060, 1) {
  using namespace std;
  class Solution {
   public:
    int n, m, v[25], w[25], ans = INT_MIN;

    void work(int idx, int money, int s) {
      if (idx >= m) {
        if (money >= 0) ans = max(ans, s);
        return;
      }
      work(idx + 1, money, s);
      work(idx + 1, money - v[idx], s + v[idx] * w[idx]);
    }

    int main() {
      cin >> n >> m;
      for (int i = 0; i < m; ++i) {
        cin >> v[i] >> w[i];
      }
      work(0, n, 0);
      cout << ans;
      return 0;
    }
  };

  Solution solution;
  solution.main();
}

TEST(leetcode_p_1060, 2) {
  using namespace std;
  class Solution {
   public:
    int n, m, v[25], w[25];

    int work(int idx, int money) {
      if (idx >= m) return 0;
      int a = 0, b = 0, ans;
      if (money >= 0) a = work(idx + 1, money);
      if (money - v[idx] >= 0)
        b = work(idx + 1, money - v[idx]) + v[idx] * w[idx];
      ans = max(a, b);
      return ans;
    }

    int main() {
      cin >> n >> m;
      for (int i = 0; i < m; ++i) {
        cin >> v[i] >> w[i];
      }
      /*
      n = 1000, m = 5;
      v[0] = 800, w[0] = 2;
      v[1] = 400, w[1] = 5;
      v[2] = 300, w[2] = 5;
      v[3] = 400, w[3] = 3;
      v[4] = 200, w[4] = 2;
       */
      cout << work(0, n);
      return 0;
    }
  };

  Solution solution;
  solution.main();
}
