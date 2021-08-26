//
// Created by XinShuoWang on 2021/8/12.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(others_21, 1) {
  using namespace std;
  class ListNodeComparator {
   public:
    bool operator()(ListNode* node1, ListNode* node2) {
      return node1->val >= node2->val;
    }
  };
  class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr && l2 == nullptr) return nullptr;
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      priority_queue<ListNode*, vector<ListNode*>, ListNodeComparator> q;
      ListNode *res = nullptr, *t = nullptr;
      bool flag = false;
      while (l1 != nullptr || l2 != nullptr) {
        if (l1 != nullptr) {
          q.push(l1);
          l1 = l1->next;
        }
        if (l2 != nullptr) {
          q.push(l2);
          l2 = l2->next;
        }
        if (!flag) {
          res = q.top();
          t = res;
          q.pop();
          flag = true;
        } else {
          t->next = q.top();
          t = t->next;
          q.pop();
        }
      }
      while (!q.empty()) {
        t = q.top();
        t = t->next;
        q.pop();
      }
      t->next = nullptr;
      return res;
    }
  };
}

TEST(others_21, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr && l2 == nullptr) return nullptr;
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      return work(l1, l2);
    }

    ListNode* work(ListNode* l1, ListNode* l2) {
      if (l1 == nullptr) return l2;
      if (l2 == nullptr) return l1;
      if (l1->val > l2->val) {
        l2->next = work(l1, l2->next);
        return l2;
      } else {
        l1->next = work(l1->next, l2);
        return l1;
      }
    }
  };
}