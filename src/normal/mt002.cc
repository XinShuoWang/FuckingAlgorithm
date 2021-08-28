//
// Created by XinShuo Wang on 2021/8/26 18:55
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_mt002, 1) {
  using namespace std;
  class MeiTuan {
   public:
    vector<int> v1, v2;
    int n, t;
    void input() {
      cin >> n;
      v1.resize(n);
      for (int i = 0; i < n; ++i) {
        cin >> v1[i];
      }
    }

    void calculate() {
      v2.resize(n + 1);
      v2[0] = 0;
      for (int i = 0; i < n; ++i) {
        v2[i + 1] = v2[i] + v1[i];
      }
    }

    int sum(int s, int e) {
      return v2[e] -v2[++s];
    }

    int main() {
      input();
      calculate();
      multiset<int> s;
      s.insert(v2[n]);
      for (int i = 0; i < n; ++i) {
        cin >> t, t--, v1[t] = 0;
        int t1 = t - 1, t2 = t + 1;
        while (t1 >= 0 && v1[t1] != 0) t1--;
        while (t2 < n && v1[t2] != 0) t2++;
        // 这里注意只能删除一个，如果简单的使用erase会删除所有值一样的
        s.erase(s.find(sum(t1, t2)));
        s.insert(sum(t1, t)), s.insert(sum(t, t2));
        cout << *s.rbegin() << endl;
      }
      return 0;
    }
  };

  MeiTuan meiTuan;
  meiTuan.main();
}