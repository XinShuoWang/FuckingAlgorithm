//
// Created by XinShuo Wang on 2021/8/24 10:28
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_116, 1) {
  using namespace std;

  // Definition for a Node.
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
      if (root == nullptr) return root;
      queue<Node*> q;
      vector<vector<Node*>> v;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        vector<Node*> vv;
        while (size > 0) {
          vv.push_back(q.front());
          if (q.front()->left != nullptr) q.push(q.front()->left);
          if (q.front()->right != nullptr) q.push(q.front()->right);
          q.pop();
          size--;
        }
        v.emplace_back(vv);
      }
      for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size() - 1; ++j) {
          v[i][j]->next = v[i][j + 1];
        }
      }
      return v[0][0];
    }
  };
}

TEST(leetcode_116, 2) {
  using namespace std;

  // Definition for a Node.
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
      if (root == nullptr) return root;
      queue<Node*> q;
      q.push(root);
      while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
          auto ref = q.front();
          q.pop();
          size--;
          if (!q.empty() && size > 0) ref->next = q.front();
          if (ref->left != nullptr) q.push(ref->left);
          if (ref->right != nullptr) q.push(ref->right);
        }
      }
      return root;
    }
  };
}

TEST(leetcode_116, 3) {
  using namespace std;

  // Definition for a Node.
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
    // 思想：在第n层把第n+1层连接好
    Node* connect(Node* root) {
      if (root == nullptr) return root;
      auto pre = root;
      // 这里要判断pre->left而不是pre
      while (pre->left != nullptr) {
        auto t = pre;
        while (t != nullptr) {
          t->left->next = t->right;
          // 这里要判断t->next，比如说在根节点时如果不判断就会出错
          if (t->next != nullptr) t->right->next = t->next->left;
          t = t->next;
        }
        pre = pre->left;
      }
      return root;
    }
  };
}