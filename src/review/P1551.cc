//
// Created by xinsh on 2021/7/30.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(disjoint_set_p1551, 1) {
  class Solution {
   private:
    int n, m, p;
    int data[5005];

   public:
    void inline init() {
      for (int i = 0; i < n; ++i) {
        data[i] = i;
      }
    }

    void inline merge(int i, int j) {
      // 要找到各自的祖先节点然后合并
      data[find(i)] = find(j);
    }

    int inline find(int x) {
      // 路径压缩
      // 如果不开启路径压缩大概是这样：return x == data[x] ? x : find(data[x]);
      // 路径压缩就是把自己直接与祖先进行关联
      return x == data[x] ? x : (data[x] = find(data[x]));
    }

    int main() {
      scanf("%d%d%d", &n, &m, &p);
      init();
      for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        merge(a, b);
      }
      for (int i = 0; i < p; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf(find(a) == find(b) ? "Yes\n" : "No\n");
      }
      return 0;
    }
  };
}
