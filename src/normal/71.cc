//
// Created by XinShuo Wang on 2022/1/6 11:42
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_71, 1) {
  using namespace std;
  class Solution {
   public:
    string simplifyPath(string& path) {
      stack<string> s;
      int i = 0, j = 1;
      while (j < path.length()) {
        while(i < path.length() && path[i] == '/') ++i;
        j = i + 1;
        while (j < path.length() && path[j] != '/') ++j;
        string dir = path.substr(i, j - i);
        // cout << dir << endl;
        if (dir == ".") {
        } else if (dir == "..") {
          if (!s.empty()) s.pop();
        } else if(dir == "") {

        } else {
          s.push(dir);
        }
        i = j++;
      }
      string ans;
      while (!s.empty()) ans = "/" + s.top() + ans, s.pop();
      return ans == "" ? "/" : ans;
    }
  };
}