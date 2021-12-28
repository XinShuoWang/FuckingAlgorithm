//
// Created by XinShuo Wang on 2021/12/21 12:15
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_141, 1) {
  using namespace std;
  class Solution {
   public:
    bool hasCycle(ListNode* head) {
      int count = 0;
      while (head != nullptr) {
        count++;
        if (count > 10001) return true;
        head = head->next;
      }
      return false;
    }
  };
}

TEST(leetcode_141, 2) {
  using namespace std;
  class Solution {
   public:
    bool hasCycle(ListNode* head) {
      auto a = head;
      if(a == nullptr) return false;
      auto b = a->next;
      while (true) {
        if (a == b) return true;
        if(a == nullptr || b == nullptr || b->next == nullptr) return false;
        b = b->next->next;
        a = a->next;
      }
      return false;
    }
  };
}