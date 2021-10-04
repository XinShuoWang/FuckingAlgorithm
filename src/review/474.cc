//
// Created by XinShuo Wang on 2021/9/30 9:14
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_474, 1) {
  using namespace std;
  class Solution {
    int ans = 0;

   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<pair<int, int>> v(strs.size());
      for (int i = 0; i < strs.size(); ++i) {
        int a = 0, b = 0;
        for (char c : strs[i]) {
          if (c == '0')
            a++;
          else
            b++;
        }
        // cout << a << "," << b << endl;
        v[i].first = a;
        v[i].second = b;
      }
      work(v, 0, 0, m, n);
      return ans;
    }

    void work(vector<pair<int, int>>& v, int x, int y, int m, int n) {
      if (m < 0 || n < 0) {
        ans = max(ans, y - 1);
        return;
      }
      if (x >= v.size()) {
        ans = max(ans, y);
        return;
      }
      work(v, x + 1, y, m, n);
      work(v, x + 1, y + 1, m - v[x].first, n - v[x].second);
    }
  };
}

TEST(leetcode_474, 2) {
  using namespace std;
  class Solution {
    unordered_map<int, int> cache;
    unordered_map<int, int>::iterator it;

    int get(int x, int m, int n) {
      int ans = x;
      ans <<= 10;
      ans += m;
      ans <<= 10;
      ans += n;
      return ans;
    }

   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      vector<pair<int, int>> v(strs.size());
      for (int i = 0; i < strs.size(); ++i) {
        int a = 0, b = 0;
        for (char c : strs[i]) {
          if (c == '0')
            a++;
          else
            b++;
        }
        // cout << a << "," << b << endl;
        v[i].first = a;
        v[i].second = b;
      }
      return work(v, 0, m, n);
    }

    int work(vector<pair<int, int>>& v, int x, int m, int n) {
      if (m < 0 || n < 0) return -1;
      if (x >= v.size()) return 0;
      if ((it = cache.find(get(x, m, n))) != cache.end()) return it->second;
      int ans = max(work(v, x + 1, m, n),
                    work(v, x + 1, m - v[x].first, n - v[x].second) + 1);
      cache[get(x, m, n)] = ans;
      return ans;
    }
  };
}