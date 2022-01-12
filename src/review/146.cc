//
// Created by XinShuoWang on 2021/8/5.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(others_146, 1) {
  using namespace std;

  struct Node {
    Node *next_, *prev_;
    int k_, v_;
    Node() {
      next_ = nullptr;
      prev_ = nullptr;
      k_ = 0;
      v_ = 0;
    }
    Node(int k, int v) {
      next_ = nullptr;
      prev_ = nullptr;
      k_ = k;
      v_ = v;
    }
  };

  class LinkedList {
    Node head_, tail_;

   public:
    LinkedList() {
      head_.next_ = &tail_;
      tail_.prev_ = &head_;
    }

    Node* AppendHead(int k, int v) {
      auto node = new Node(k, v);
      // t是原来head后面紧跟着的元素
      auto t = head_.next_;
      // 后向指针
      head_.next_ = node;
      node->next_ = t;
      // 前向指针
      t->prev_ = node;
      node->prev_ = &head_;
      return node;
    }

    void ModeHead(Node* node) {
      {
        auto before = node->prev_;
        auto after = node->next_;
        before->next_ = after;
        after->prev_ = before;
      }
      {
        auto t = head_.next_;
        head_.next_ = node;
        node->next_ = t;
        t->prev_ = node;
        node->prev_ = &head_;
      }
    }

    int DeleteLast() {
      auto node1 = tail_.prev_, node2 = tail_.prev_->prev_;
      node2->next_ = &tail_;
      tail_.prev_ = node2;
      int res = node1->k_;
      delete node1;
      return res;
    }
  };

  class LRUCache {
    int capacity_, count_;
    map<int, Node*> m;
    LinkedList linked_list_;

   public:
    LRUCache(int capacity) {
      capacity_ = capacity;
      count_ = 0;
    }

    int get(int key) {
      if (m.count(key) == 0) {
        return -1;
      } else {
        linked_list_.ModeHead(m[key]);
        return m[key]->v_;
      }
    }

    void put(int key, int value) {
      bool exist = (m.count(key) != 0);
      if (exist && count_ < capacity_) {
        m[key]->v_ = value;
        linked_list_.ModeHead(m[key]);
      } else if (exist && count_ == capacity_) {
        m[key]->v_ = value;
        linked_list_.ModeHead(m[key]);
      } else if (!exist && count_ < capacity_) {
        auto node = linked_list_.AppendHead(key, value);
        m[key] = node;
        count_++;
      } else if (!exist && count_ == capacity_) {
        m.erase(linked_list_.DeleteLast());
        auto node = linked_list_.AppendHead(key, value);
        m[key] = node;
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


TEST(leetcode_146, 2) {
  using namespace std;
  class LRUCache {
    int capacity_;
    list<pair<int, int>> list_;
    map<int, list<pair<int, int>>::iterator> map_;

   public:
    LRUCache(int capacity) { capacity_ = capacity; }

    int get(int key) {
      // cout << "Get:" << key << endl;
      map<int, list<pair<int, int>>::iterator>::iterator it;
      if ((it = map_.find(key)) != map_.end()) {
        int value = it->second->second;
        list_.erase(it->second);
        list_.push_front(make_pair(key, value));
        map_[key] = list_.begin();
        return value;
      } else {
        return -1;
      }
    }

    void put(int key, int value) {
      // cout << "Put:" << key << "," << value << endl;
      map<int, list<pair<int, int>>::iterator>::iterator it;
      if ((it = map_.find(key)) == map_.end()) {
        if (map_.size() >= capacity_) {
          int k = list_.back().first;
          list_.pop_back();
          map_.erase(k);
        }
      } else {
        list_.erase(it->second);
      }
      list_.push_front(make_pair(key, value));
      map_[key] = list_.begin();
    }
  };
  /**
   * Your LRUCache object will be instantiated and called as such:
   * LRUCache* obj = new LRUCache(capacity);
   * int param_1 = obj->get(key);
   * obj->put(key,value);
   */
}