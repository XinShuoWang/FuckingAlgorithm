//
// Created by XinShuoWang on 2021/8/12.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "ListNode.h"

TEST(linked_list_206, 1) {
  using namespace std;
  class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return head;
      if (head->next == nullptr) return head;
      ListNode* last = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr;
      return last;
    }
  };
}

TEST(linked_list_206, 2) {
  using namespace std;
  class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return nullptr;
      vector<ListNode*> v;
      ListNode* t = head;
      while (t != nullptr) {
        v.push_back(t);
        t = t->next;
      }
      int i;
      for (i = v.size() - 1; i > 0; --i) {
        v[i]->next = v[i - 1];
      }
      v[i]->next = nullptr;
      return v[v.size() - 1];
    }
  };
}

TEST(linked_list_206, 3) {
  using namespace std;
  class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr) return nullptr;
      return work(head);
    }

    // 递归巧妙地利用递归栈保存变量
    ListNode* work(ListNode* head) {
      if (head->next == nullptr) return head;
      // 这里的变量是要最后返回的，一直返回回去，因为这是头结点
      ListNode* t = work(head->next);
      head->next->next = head;
      head->next = nullptr;
      return t;
    }
  };

  ListNode node1(1), node2(2), node3(3);
  node1.next = &node2;
  node2.next = &node3;
  Solution solution;
  solution.reverseList(&node1);
}