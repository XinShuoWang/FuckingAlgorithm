//
// Created by XinShuo Wang on 2021/9/23 9:58
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_622, 1) {
  using namespace std;
  class MyCircularQueue {
    int left, right, size;
    vector<int> v;
   public:
    MyCircularQueue(int k) {
      left = right = 0;
      size = k;
      v.resize(k, 0);
    }

    bool enQueue(int value) {

    }

    bool deQueue() {}

    int Front() {}

    int Rear() {}

    bool isEmpty() {}

    bool isFull() {}
  };

  /**
   * Your MyCircularQueue object will be instantiated and called as such:
   * MyCircularQueue* obj = new MyCircularQueue(k);
   * bool param_1 = obj->enQueue(value);
   * bool param_2 = obj->deQueue();
   * int param_3 = obj->Front();
   * int param_4 = obj->Rear();
   * bool param_5 = obj->isEmpty();
   * bool param_6 = obj->isFull();
   */
}