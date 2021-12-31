//
// Created by XinShuo Wang on 2021/12/28 21:00
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"
#include "TreeNode.h"

TEST(leetcode_232, 1) {
  using namespace std;
  class MyQueue {
    stack<int> s;

   public:
    void push(int x) {
      stack<int> t;
      while (!s.empty()) t.push(s.top()), s.pop();
      s.push(x);
      while (!t.empty()) s.push(t.top()), t.pop();
    }

    int pop() {
      int ans = s.top();
      s.pop();
      return ans;
    }

    int peek() { return s.top(); }

    bool empty() { return s.empty(); }
  };
}

TEST(leetcode_232, 2) {
  using namespace std;
  class MyQueue {
    stack<int> input, output;

    void work() {
      while (!input.empty()) output.push(input.top()), input.pop();
    }

   public:
    void push(int x) { input.push(x); }

    int pop() {
      if (output.empty()) work();
      int ans = output.top();
      output.pop();
      return ans;
    }

    int peek() {
      if (output.empty()) work();
      return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }
  };
}

namespace namespace_232 {
template <typename T>
class Stack {
 private:
  struct Node {
    Node* before;
    Node* after;
    T val;
    Node(T _) {
      before = nullptr;
      after = nullptr;
      val = _;
    }
  };
  Node* head_;
  Node* tail_;

 public:
  Stack() {
    head_ = new Node(0);
    tail_ = new Node(0);
    head_->after = tail_;
    tail_->before = head_;
  }

  ~Stack() {
    delete head_;
    delete tail_;
  }

  void pop() {
    if (empty()) return;
    auto temp = tail_->before;
    tail_->before = temp->before;
    temp->before->after = tail_;
    delete temp;
  }

  T top() { return tail_->before->val; }

  void push(T x) {
    Node* temp = new Node(x);
    temp->after = tail_;
    temp->before = tail_->before;
    tail_->before->after = temp;
    tail_->before = temp;
  }

  bool empty() { return head_->after == tail_; }
};
}  // namespace namespace_232

TEST(leetcode_232, 3) {
  using namespace std;
  class MyQueue {
    namespace_232::Stack<int> input, output;

    void work() {
      while (!input.empty()) output.push(input.top()), input.pop();
    }

   public:
    void push(int x) { input.push(x); }

    int pop() {
      if (output.empty()) work();
      int ans = output.top();
      output.pop();
      return ans;
    }

    int peek() {
      if (output.empty()) work();
      return output.top();
    }

    bool empty() { return input.empty() && output.empty(); }
  };
}