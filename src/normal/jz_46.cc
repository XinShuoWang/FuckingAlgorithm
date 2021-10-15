//
// Created by XinShuo Wang on 2021/10/12 9:51
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_46, 1) {
  using namespace std;
  class Solution {
    int ans = 0;

   public:
    int translateNum(int num) {
      string s;
      while (num != 0) {
        // cout << char('0' + num % 10) << endl;
        s.insert(s.begin(), char('0' + num % 10));
        num /= 10;
      }
      // cout << s << endl;
      work(s, 0);
      return ans;
    }

    void work(string& s, int idx) {
      if (idx >= s.length()) {
        ans++;
        return;
      }
      work(s, idx + 1);
      if (idx + 1 < s.length() &&
          ((s[idx] == '1' && s[idx + 1] <= '9' && s[idx] >= '0') ||
           (s[idx] == '2' && s[idx + 1] <= '5' && s[idx] >= '0')))
        work(s, idx + 2);
    }
  };
}



TEST(leetcode_jz_46, 2) {
  using namespace std;
  class Solution {
   public:
    int translateNum(int num) {
      
    }
  };
}