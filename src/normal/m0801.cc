//
// Created by XinShuoWang on 2021/8/12.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_m0801, 1) {
  using namespace std;
  class Solution {
    typedef long long ll;
    map<int, ll> cache;

   public:
    int waysToStep(int n) { return work(n); }

    ll work(int n) {
      if (n <= 0) return 0;
      if (n == 1) return 1;
      if (n == 2) return 2;
      if (n == 3) return 4;
      if (cache.count(n) != 0) return cache[n];
      ll res = work(n - 1) + work(n - 2) + work(n - 3);
      cache[n] = res;
      return res % 1000000007;
    }
  };
}

TEST(dp_m0801, 2) {
  using namespace std;
  class Solution {
    typedef __int128 ll;

   public:
    int waysToStep(int n) {
      switch (n) {
        case 1:
          return 1;
        case 2:
          return 2;
        case 3:
          return 4;
        default:
          vector<ll> v(n + 1, 0);
          v[1] = 1;
          v[2] = 2;
          v[3] = 4;
          for (int i = 4; i <= n; ++i) {
            v[i] = (v[i - 1] + v[i - 2] + v[i - 3] + 7)  % 1000000007;
          }
          return v[n] % 1000000007;
      }
    }
  };
}