//
// Created by XinShuoWang on 2021/8/12.
//

#ifndef FUCKINGALGORITHM_INCLUDE_LISTNODE_H_
#define FUCKINGALGORITHM_INCLUDE_LISTNODE_H_

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#endif  // FUCKINGALGORITHM_INCLUDE_LISTNODE_H_
