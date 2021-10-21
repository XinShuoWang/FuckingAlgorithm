//
// Created by XinShuo Wang on 2021/10/19 14:44
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(leetcode_jz_12, 1) {
  using namespace std;
  class Solution {
    string path;
    vector<vector<bool>> visited;

   public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size(), n = board[0].size();
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          visited.resize(m, vector<bool>(n, false));
          path.push_back(board[i][j]);
          visited[i][j] = true;
          if (work(board, word, i, j)) return true;
          path.pop_back();
          visited[i][j] = false;
        }
      }
      return false;
    }

    bool work(vector<vector<char>>& board, string& word, int i, int j) {
      if (path.length() == word.length()) {
        return path == word;
      }
      bool ans = false;
      int a = i - 1, b = j;
      if (a >= 0 && !visited[a][b]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      a = i + 1, b = j;
      if (i + 1 < board.size() && !visited[i + 1][j]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      a = i, b = j - 1;
      if (j - 1 >= 0 && !visited[i][j - 1]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      a = i, b = j + 1;
      if (j + 1 < board[0].size() && !visited[i][j + 1]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      return ans;
    }
  };

  vector<vector<char>> v{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  Solution solution;
  solution.exist(v, "ABCCED");
}





TEST(leetcode_jz_12, 2) {
  using namespace std;
  class Solution {
    string path;
    vector<vector<bool>> visited;

   public:
    bool exist(vector<vector<char>>& board, string word) {
      int m = board.size(), n = board[0].size();
      for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
          visited.resize(m, vector<bool>(n, false));
          path.push_back(board[i][j]);
          visited[i][j] = true;
          if (board[i][j] == word[0] && work(board, word, i, j)) return true;
          path.pop_back();
          visited[i][j] = false;
        }
      }
      return false;
    }

    bool work(vector<vector<char>>& board, string& word, int i, int j) {
      if (path.length() == word.length()) {
        return path == word;
      }
      bool ans = false;
      int a = i - 1, b = j;
      if (a >= 0 && !visited[a][b] && board[a][b] == word[path.size()]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      if(ans) return true;
      a = i + 1, b = j;
      if (i + 1 < board.size() && !visited[i + 1][j] && board[a][b] == word[path.size()]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      if(ans) return true;
      a = i, b = j - 1;
      if (j - 1 >= 0 && !visited[i][j - 1] && board[a][b] == word[path.size()]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      if(ans) return true;
      a = i, b = j + 1;
      if (j + 1 < board[0].size() && !visited[i][j + 1] && board[a][b] == word[path.size()]) {
        path.push_back(board[a][b]);
        visited[a][b] = true;
        ans |= work(board, word, a, b);
        path.pop_back();
        visited[a][b] = false;
      }
      return ans;
    }
  };

  vector<vector<char>> v{
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  Solution solution;
  solution.exist(v, "ABCCED");
}