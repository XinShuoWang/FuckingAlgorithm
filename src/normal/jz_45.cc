//
// Created by XinShuo Wang on 2021/10/21 13:12
//
#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <gtest/gtest.h>

TEST(leetcode_jz_45, 1) {
  using namespace std;
  class Solution {
    string path, ans;
    vector<bool> visited;

   public:
    Solution() { visited.resize(100, false); }

    string itoa(int x) {
      if (x == 0) return "0";
      string t = "";
      while (x != 0) {
        t.insert(t.begin(), x % 10 + '0');
        x /= 10;
      }
      return t;
    }

    bool ok(int len) {
      for (int i = 0; i < len; ++i) {
        if (!visited[i]) return true;
      }
      return false;
    }

    void work(vector<int>& nums) {
      if (!ok(nums.size())) {
        cout << path << endl;
        if (ans.empty()) {
          ans = path;
        } else {
          if (strcmp(path.c_str(), ans.c_str()) < 0) ans = path;
        }
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (!visited[i]) {
          visited[i] = true;
          path.append(itoa(nums[i]));
          minNumber(nums);
          int t = nums[i];
          if (t == 0) path.pop_back();
          while (t != 0) {
            path.pop_back();
            t /= 10;
          }
          visited[i] = false;
        }
      }
    }

    string minNumber(vector<int>& nums) {
      work(nums);
      return ans;
    }
  };
}

TEST(leetcode_jz_45, 2) {
  using namespace std;
  class Solution {
   public:
    string minNumber(vector<int>& nums) {
      vector<string> strs;
      for (int num : nums) strs.push_back(to_string(num));
      sort(strs.begin(), strs.end(),
           [](string& a, string& b) { return a + b < b + a; });
      string ans;
      for (string& s : strs) ans.append(s);
      return ans;
    }
  };
}