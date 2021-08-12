//
// Created by XinShuoWang on 2021/8/11.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(dp_121, 1) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      int res = 0;
      for (int i = 0; i < prices.size(); ++i) {
        for (int j = i + 1; j < prices.size(); ++j) {
          if (prices[j] - prices[i] > res) res = prices[j] - prices[i];
        }
      }
      return res;
    }
  };
}

TEST(dp_121, 2) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      vector<int> v(prices.size(), 0);
      v[0] = prices[0];
      for (int i = 1; i < v.size(); ++i) {
        v[i] = min(v[i - 1], prices[i]);
      }
      int res = 0;
      for (int i = 1; i < v.size(); ++i) {
        res = max(res, prices[i] - v[i - 1]);
      }
      return res;
    }
  };
}

TEST(dp_121, 3) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      vector<int> v(prices.size(), 0);
      v[0] = prices[0];
      int res = 0;
      for (int i = 1; i < v.size(); ++i) {
        v[i] = min(v[i - 1], prices[i]);
        res = max(res, prices[i] - v[i - 1]);
      }
      return res;
    }
  };
}

TEST(dp_121, 4) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      int res = 0, val = prices[0];
      for (int i = 1; i < prices.size(); ++i) {
        res = max(res, prices[i] - val);
        val = min(val, prices[i]);
      }
      return res;
    }
  };
}

TEST(dp_121, 5) {
  using namespace std;
  class Solution {
   public:
    int maxProfit(vector<int>& prices) {
      int res = 0, min = INT_MAX;
      for (int i = 0; i < prices.size(); ++i) {
        if (min > prices[i]) {
          min = prices[i];
        } else {
          res = max(res, prices[i] - min);
        }
      }
      return res;
    }
  };
}