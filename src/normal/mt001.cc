//
// Created by XinShuo Wang on 2021/8/26 18:30
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_mt0001, 1) {
  using namespace std;

  class MeiTuan {
   public:
    bool ok(string& s) {
      if (s.length() < 1) return false;
      if (!isupper(s[0]) && !islower(s[0])) return false;
      int pos = 1;
      bool ans = false;
      while (pos < s.length()) {
        if (!isalnum(s[pos])) return false;
        if (!ans && isdigit(s[pos])) ans = true;
        pos++;
      }
      return true && ans;
    }

    int main() {
      int n;
      cin >> n;
      for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cout << (ok(s) ? "Accept" : "Wrong") << endl;
      }
      return 0;
    }
  };
}
