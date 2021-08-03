//
// Created by xinsh on 2021/8/2.
//
#include <bits/stdc++.h>
#include <gtest/gtest.h>

TEST(backtarce_46, 1) {
    using namespace std;
    class Solution {
    private:
        vector<vector<int>> res_;
        vector<int> path_;
        vector<bool> used_;

        inline bool allUsed() {
            for (int i = 0; i < used_.size(); ++i) {
                if (!used_[i]) return false;
            }
            return true;
        }

    public:
        vector<vector<int>> permute(vector<int> &nums) {
            for (int i = 0; i < nums.size(); ++i) {
                used_.push_back(false);
            }
            helper(nums);
            return res_;
        }

        void helper(vector<int> &nums) {
            if (allUsed()) {
                res_.push_back(path_);
                return;
            }
            for (int i = 0; i < nums.size(); ++i) {
                if (!used_[i]) {
                    used_[i] = true;
                    path_.push_back(nums[i]);
                    helper(nums);
                    used_[i] = false;
                    path_.pop_back();
                }
            }
        }
    };
}
