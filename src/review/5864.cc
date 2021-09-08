//
// Created by XinShuo Wang on 2021/9/5 12:33
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_5864, 1) {
  using namespace std;
  class Solution {
   public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      sort(properties.begin(), properties.end(),
           [](const vector<int>& v1, const vector<int>& v2) {
             if (v1[0] == v2[0]) return v1[1] < v2[1];
             return v1[0] < v2[0];
           });
      vector<int> m(properties.size(), 0);
      m[properties.size() - 1] = properties[properties.size() - 1][1];
      for (int i = properties.size() - 2; i > 0; --i) {
        m[i] = max(m[i + 1], properties[i][1]);
      }
      int ans = 0;
      for (int i = 0; i < properties.size(); ++i) {
        // cout << properties[i][0] << "," << properties[i][1] << "," << m[i] << endl;
        int j = i + 1;
        while (j < properties.size() && properties[j][0] == properties[i][0])
          ++j;
        if (j < properties.size() && m[j] > properties[i][1]) {
          ans++;
        }
      }
      return ans;
    }
  };
}