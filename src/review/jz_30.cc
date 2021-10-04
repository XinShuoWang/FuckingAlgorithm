//
// Created by XinShuo Wang on 2021/10/4 13:14
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_30, 1) {
  using namespace std;
  class MinStack {
    stack<pair<int, int>> s;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
      //   √      |      ×
      // -2  -2   |  -2    INT_MAX
      //  0  -2   |   0       0
      // -3  -3   |  -3      -3
      if (s.empty()) {
        s.push(make_pair(x, x));
      } else {
        s.push(make_pair(x, std::min(x, s.top().second)));
      }
    }

    void pop() { s.pop(); }

    int top() { return s.top().first; }

    int min() { return s.top().second; }
  };

  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(x);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->min();
   */
}

TEST(leetcode_jz_30, 2) {
  using namespace std;
  class MinStack {
    stack<int> s;
    vector<int> v;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
      s.push(x);
      if (!v.empty()) {
        v.push_back(std::min(v.back(), x));
      } else {
        v.push_back(x);
      }
    }

    void pop() {
      s.pop();
      v.pop_back();
    }

    int top() { return s.top(); }

    int min() { return v.back(); }
  };

  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(x);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->min();
   */
}

TEST(leetcode_jz_30, 3) {
  using namespace std;
  class MinStack {
    stack<int> s1, s2;

   public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int x) {
      s1.push(x);
      if (!s2.empty()) {
        s2.push(std::min(s2.top(), x));
      } else {
        s2.push(x);
      }
    }

    void pop() {
      s1.pop();
      s2.pop();
    }

    int top() { return s1.top(); }

    int min() { return s2.top(); }
  };

  /**
   * Your MinStack object will be instantiated and called as such:
   * MinStack* obj = new MinStack();
   * obj->push(x);
   * obj->pop();
   * int param_3 = obj->top();
   * int param_4 = obj->min();
   */
}