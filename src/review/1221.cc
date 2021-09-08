//
// Created by XinShuo Wang on 2021/9/7 9:28
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1221, 1) {
  using namespace std;
  class Solution {
    vector<pair<int, int>> v;

   public:
    int balancedStringSplit(string s) {
      int ans = 0, left, right;
      work(s);
      for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 2; j < s.length(); j += 2) {
          left = v[j].first - v[i].first;
          right = v[j].second - v[i].second;
          if (left == right) {
            cout << left << "," << right << endl;
            ans++;
          }
        }
      }
      return ans;
    }

    void work(string& s) {
      int left = 0, right = 0;
      for (char c : s) {
        if (c == 'L')
          left++;
        else
          right++;
        v.emplace_back(make_pair(left, right));
      }
    }
  };
}