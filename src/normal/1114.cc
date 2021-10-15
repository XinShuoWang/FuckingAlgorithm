//
// Created by XinShuo Wang on 2021/10/10 14:31
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_1114, 1) {
  using namespace std;
  class Foo {
   private:
    int count;
    mutex lock;
    condition_variable cv;

   public:
    Foo() { count = 1; }

    void first(function<void()> printFirst) {
      // printFirst() outputs "first". Do not change or remove this line.
      printFirst();
      count++;
      // 这里为啥使用notify_all呢？
      // 我认为是在此时2和3都在wait，只notify一个的话不知道会“叫醒”哪一个，如果叫醒了3
      // 3发现自己不满足条件就又“睡了”，此时2还在等，这就GG了
      cv.notify_all();
    }

    void second(function<void()> printSecond) {
      unique_lock<mutex> u(lock);
      cv.wait(u, [&] { return count == 2; });
      // printSecond() outputs "second". Do not change or remove this line.
      printSecond();
      count++;
      cv.notify_all();
    }

    void third(function<void()> printThird) {
      unique_lock<mutex> u(lock);
      cv.wait(u, [&] { return count == 3; });
      // printThird() outputs "third". Do not change or remove this line.
      printThird();
    }
  };
}