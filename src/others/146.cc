//
// Created by XinShuoWang on 2021/8/5.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_146, 1) {
  using namespace std;
  class LRUCache {
    int capacity_, count_;
    map<int, int> store_;
    list<int> used_;
    void use(int key, bool exist) {
      if (!exist) {
        used_.insert(used_.begin(), key);
      } else {
        used_.erase(std::find(used_.begin(), used_.end(), key));
        used_.insert(used_.begin(), key);
      }
    }

   public:
    LRUCache(int capacity) {
      capacity_ = capacity;
      count_ = 0;
    }

    int get(int key) {
      if (store_.count(key) == 0) {
        return -1;
      } else {
        use(key, true);
        return store_[key];
      }
    }

    void put(int key, int value) {
      if (count_ < capacity_) {
        if (store_.count(key) == 0) {
          store_[key] = value;
          count_++;
          use(key, false);
        } else {
          store_[key] = value;
          use(key, true);
        }
      } else {
        if (store_.count(key) == 0) {
          store_.erase(used_.back());
          used_.pop_back();
          store_[key] = value;
          use(key, false);
        } else {
          store_[key] = value;
          use(key, true);
        }
      }
    }
  };

  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache* obj = new LRUCache(capacity);
   * int param_1 = obj->get(key);
   * obj->put(key,value);
   */
}