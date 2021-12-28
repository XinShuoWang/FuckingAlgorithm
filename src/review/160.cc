//
// Created by XinShuo Wang on 2021/12/21 14:30
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(leetcode_160, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      set<ListNode*> s;
      while (headA != nullptr) s.insert(headA), headA = headA->next;
      while (headB != nullptr) {
        if (s.find(headB) != s.end()) return headB;
        headB = headB->next;
      }
      return nullptr;
    }
  };
}

TEST(leetcode_160, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
      // 核心思路是把两个链表“搞”成一样长的
      auto a = headA, b = headB;
      while (a != b) {
        // 在第二轮结束的时候，两个指针走了一样的路程，这时候如果没有交集，那么两个指针都会是null
        a = a != nullptr ? a->next : headB;
        b = b != nullptr ? b->next : headA;
      }
      return a;
    }
  };
}