//
// Created by xinsh on 2021/8/3.
//

#ifndef FUCKINGALGORITHM_NODE_H
#define FUCKINGALGORITHM_NODE_H

#include <bits/stdc++.h>

class Node {
 public:
  int val;
  std::vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, std::vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

#endif  // FUCKINGALGORITHM_NODE_H
