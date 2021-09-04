//
// Created by XinShuo Wang on 2021/9/3 10:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_130, 1) {
  using namespace std;
  class Solution {
   public:
    void solve(vector<vector<char>>& board) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == 'O' && !work(board, i, j)) {
            fuck(board, i, j);
          }
        }
      }
    }

    void fuck(vector<vector<char>>& board, int x, int y) {
      queue<pair<int, int>> q;
      q.push(make_pair(x, y));
      board[x][y] = 'X';
      while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        if (board[a - 1][b] == 'O') {
          q.push(make_pair(a - 1, b));
          board[a - 1][b] = 'X';
        }
        if (board[a + 1][b] == 'O') {
          q.push(make_pair(a + 1, b));
          board[a + 1][b] = 'X';
        }
        if (board[a][b - 1] == 'O') {
          q.push(make_pair(a, b - 1));
          board[a][b - 1] = 'X';
        }
        if (board[a][b + 1] == 'O') {
          q.push(make_pair(a, b + 1));
          board[a][b + 1] = 'X';
        }
        q.pop();
      }
    }

    bool work(vector<vector<char>>& board, int x, int y) {
      vector<vector<bool>> visited(board.size(),
                                   vector<bool>(board[0].size(), false));
      queue<pair<int, int>> q;
      q.push(make_pair(x, y));
      visited[x][y] = true;
      while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        if (a == 0 || a == board.size() - 1 || b == 0 ||
            b == board[0].size() - 1) {
          return true;
        }
        if (board[a - 1][b] == 'O' && !visited[a - 1][b]) {
          q.push(make_pair(a - 1, b));
          visited[a - 1][b] = true;
        }
        if (board[a + 1][b] == 'O' && !visited[a + 1][b]) {
          q.push(make_pair(a + 1, b));
          visited[a + 1][b] = true;
        }
        if (board[a][b - 1] == 'O' && !visited[a][b - 1]) {
          q.push(make_pair(a, b - 1));
          visited[a][b - 1] = true;
        }
        if (board[a][b + 1] == 'O' && !visited[a][b + 1]) {
          q.push(make_pair(a, b + 1));
          visited[a][b + 1] = true;
        }
        q.pop();
      }
      return false;
    }
  };
}




TEST(leetcode_130, 2) {
  using namespace std;
  class Solution {
   public:
    void solve(vector<vector<char>>& board) {
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          if (board[i][j] == 'O' && !work(board, i, j)) {
            fuck(board, i, j);
          }
        }
      }
    }

    void fuck(vector<vector<char>>& board, int x, int y) {
      queue<pair<int, int>> q;
      q.push(make_pair(x, y));
      board[x][y] = 'X';
      while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        if (board[a - 1][b] == 'O') {
          q.push(make_pair(a - 1, b));
          board[a - 1][b] = 'X';
        }
        if (board[a + 1][b] == 'O') {
          q.push(make_pair(a + 1, b));
          board[a + 1][b] = 'X';
        }
        if (board[a][b - 1] == 'O') {
          q.push(make_pair(a, b - 1));
          board[a][b - 1] = 'X';
        }
        if (board[a][b + 1] == 'O') {
          q.push(make_pair(a, b + 1));
          board[a][b + 1] = 'X';
        }
        q.pop();
      }
    }

    bool work(vector<vector<char>>& board, int x, int y) {
      vector<vector<bool>> visited(board.size(),
                                   vector<bool>(board[0].size(), false));
      queue<pair<int, int>> q;
      q.push(make_pair(x, y));
      visited[x][y] = true;
      while (!q.empty()) {
        int a = q.front().first, b = q.front().second;
        if (a == 0 || a == board.size() - 1 || b == 0 ||
            b == board[0].size() - 1) {
          return true;
        }
        if (board[a - 1][b] == 'O' && !visited[a - 1][b]) {
          q.push(make_pair(a - 1, b));
          visited[a - 1][b] = true;
        }
        if (board[a + 1][b] == 'O' && !visited[a + 1][b]) {
          q.push(make_pair(a + 1, b));
          visited[a + 1][b] = true;
        }
        if (board[a][b - 1] == 'O' && !visited[a][b - 1]) {
          q.push(make_pair(a, b - 1));
          visited[a][b - 1] = true;
        }
        if (board[a][b + 1] == 'O' && !visited[a][b + 1]) {
          q.push(make_pair(a, b + 1));
          visited[a][b + 1] = true;
        }
        q.pop();
      }
      return false;
    }
  };
}