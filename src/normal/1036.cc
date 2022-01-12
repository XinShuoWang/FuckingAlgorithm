//
// Created by XinShuo Wang on 2022/1/11 14:49
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_1036, 1) {
  using namespace std;
  class Solution {
   public:
    uint64_t combine(int x, int y) {
      uint64_t ans = x;
      ans <<= 32;
      ans += y;
      return ans;
    }

    auto split(uint64_t val) {
      int x = (val >> 32);
      int y = (val & 0x00000000ffffffff);
      return make_tuple(x, y);
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source,
                          vector<int>& target) {
      const int n = ((blocked.size() - 1) * (blocked.size())) / 2;
      unordered_set<uint64_t> s;
      for (auto& block : blocked) s.insert(combine(block[0], block[1]));

      uint64_t ss = combine(source[0], source[1]);
      uint64_t tt = combine(target[0], target[1]);

      int ans = ok(ss, tt, n, s);
      if (ans == 2)
        return true;
      else if (ans == 1)
        return ok(tt, UINT64_MAX, n, s) == 1;
      else
        return false;
    }

    int ok(uint64_t start, uint64_t end, const int n,
           unordered_set<uint64_t> s) {
      int ans = 1;
      queue<uint64_t> q;
      auto [a, b] = split(start);
      q.push(start);
      s.insert(start);
      while (!q.empty()) {
        if (ans > n) return 1;
        auto [x, y] = split(q.front());
        if (q.front() == end) return 2;
        q.pop();
        if (x - 1 >= 0 && s.find(combine(x - 1, y)) == s.end())
          q.push(combine(x - 1, y)), s.insert(combine(x - 1, y)), ans++;
        if (x + 1 < 1000000 && s.find(combine(x + 1, y)) == s.end())
          q.push(combine(x + 1, y)), s.insert(combine(x + 1, y)), ans++;
        if (y - 1 >= 0 && s.find(combine(x, y - 1)) == s.end())
          q.push(combine(x, y - 1)), s.insert(combine(x, y - 1)), ans++;
        if (y + 1 < 1000000 && s.find(combine(x, y + 1)) == s.end())
          q.push(combine(x, y + 1)), s.insert(combine(x, y + 1)), ans++;
      }
      return 3;
    }
  };
}