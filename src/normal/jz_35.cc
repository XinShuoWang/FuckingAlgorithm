//
// Created by XinShuo Wang on 2021/10/5 15:59
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_35, 1) {
  using namespace std;
  // Definition for a Node.
  class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
      val = _val;
      next = NULL;
      random = NULL;
    }
  };
  class Solution {
   public:
    Node* copyRandomList(Node* head) {
      if (head == nullptr) return nullptr;
      unordered_map<Node*, int> m1;
      unordered_map<int, Node*> m2;
      Node *a = nullptr, *b = nullptr, *ans = nullptr;
      int count = 0;
      // traverse
      a = head;
      while (a != nullptr) {
        m1[a] = count++;
        a = a->next;
      }
      // new
      a = head;
      ans = new Node(a->val);
      m2[0] = ans;
      b = ans;
      count = 1;
      while (a->next != nullptr) {
        b->next = new Node(a->next->val);
        m2[count] = b->next;
        b = b->next;
        a = a->next;
        count++;
      }
      // special
      m1[nullptr] = -1;
      m2[-1] = nullptr;
      // concat
      a = head, b = ans;
      while (a != nullptr) {
        b->random = m2[m1[a->random]];
        b = b->next;
        a = a->next;
      }
      return ans;
    }
  };
}