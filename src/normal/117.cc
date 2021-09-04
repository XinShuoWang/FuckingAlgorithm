//
// Created by XinShuo Wang on 2021/9/2 9:09
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_117, 1) {
  using namespace std;
  class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
  };

  class Solution {
   public:
    Node* connect(Node* root) {
      if (root == nullptr) return nullptr;
      Node* ans = nullptr;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        vector<Node*> v;
        while (size > 0) {
          v.push_back(q.front());
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          size--;
          q.pop();
        }
        for (int i = 0; i < v.size() - 1; ++i) {
          v[i]->next = v[i + 1];
        }
        v[v.size() - 1]->next = nullptr;
        if (ans == nullptr) ans = v[0];
      }
      return ans;
    }
  };
}

TEST(leetcode_117, 2) {
  using namespace std;
  class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
  };

  class Solution {
   public:
    Node* connect(Node* root) {
      if (root == nullptr) return nullptr;
      Node* ans = nullptr;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        Node* pre = nullptr;
        while (size > 0) {
          if (pre == nullptr) {
            pre = q.front();
            if (ans == nullptr) {
              ans = q.front();
            }
          } else {
            pre->next = q.front();
            pre = pre->next;
          }
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          size--;
          q.pop();
        }
      }
      return ans;
    }
  };
}


TEST(leetcode_117, 3) {
  using namespace std;
  class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
  };

  class Solution {
   public:
    Node* connect(Node* root) {
      if (root == nullptr) return nullptr;

    }
  };
}