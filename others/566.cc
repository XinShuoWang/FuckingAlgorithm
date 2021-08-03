//
// Created by xinsh on 2021/8/3.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(othres_566, 1) {
    using namespace std;
    class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
            int m = mat.size(), n = mat[0].size();
            if (r * c != m * n) return mat;
            vector<int> v;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    v.push_back(mat[i][j]);
                }
            }
            vector <vector<int>> res(r, vector<int>(c, 0));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    // 这里应该是i * c + j
                    res[i][j] = v[i * c + j];
                }
            }
            return res;
        }
    };

    Solution solution;
    vector<vector<int>> v;
    v.push_back(vector<int>{1, 2});
    v.push_back(vector<int>{3, 4});
    vector<vector<int>> res = solution.matrixReshape(v, 4, 1);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[0].size(); ++j) {
            cout << res[i][j] << ",";
        }
        cout << endl;
    }
}


TEST(othres_566, 2) {
    using namespace std;
    class Solution {
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
            int m = mat.size(), n = mat[0].size();
            if (r * c != m * n) return mat;
            vector <vector<int>> res(r, vector<int>(c, 0));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    // 这里应该是i * c + j
                    int index = i * c + j;
                    res[i][j] = mat[index / m][index % m];
                }
            }
            return res;
        }
    };
}