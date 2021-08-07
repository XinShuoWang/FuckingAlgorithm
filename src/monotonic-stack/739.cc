//
// Created by XinShuoWang on 2021/8/7.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_739, example) {
  using namespace std;
  class Solution {
   public:
    // 单调栈的经典应用
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      // 递减栈，只有递减的时候不会出结果，否则就可以出结果了
      stack<int> st;
      vector<int> result(temperatures.size(), 0);
      st.push(0);
      for (int i = 1; i < temperatures.size(); i++) {
        if (temperatures[i] < temperatures[st.top()]) {
          // 情况一
          st.push(i);
        } else if (temperatures[i] == temperatures[st.top()]) {
          // 情况二
          st.push(i);
        } else {
          // 情况三
          while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            result[st.top()] = i - st.top();
            st.pop();
          }
          st.push(i);
        }
      }
      return result;
    }
  };
}

TEST(others_739, my_answer) {
  using namespace std;
  class Solution {
   public:
    // 单调栈的经典应用
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      // 递减栈，只有递减的时候不会出结果，否则就可以出结果了
      vector<int> res(temperatures.size(), 0);
      stack<int> s;
      s.push(0);
      for (int i = 1; i < temperatures.size(); ++i) {
        if (temperatures[s.top()] < temperatures[i]) {
          while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
            // 一直出栈，直到不满足条件，满足条件意味着res[s.top()]可以得出结论了：就是i满足
            res[s.top()] = i - s.top();
            s.pop();
          }
          // 栈为空或者大于之后：把i入栈，重新构成单调栈
          s.push(i);
        } else if (temperatures[s.top()] == temperatures[i]) {
          s.push(i);
        } else {
          s.push(i);
        }
      }
      return res;
    }
  };

  Solution solution;
  vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
  solution.dailyTemperatures(temperatures);
}