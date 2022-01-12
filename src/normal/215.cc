class Solution {
public:
    int sort(vector<int>& nums, int start, int end, int k) {
        //cout << start << "," << end << endl;
        if(start >= end) return nums[start];
        int i = start, j = end, flag = nums[start];
        while(i < j) {
            while(i < j && nums[j] <= flag) --j;
            while(i < j && nums[i] >= flag) ++i;
            if(i < j) swap(nums[i], nums[j]);
        }
        if(j == k) return nums[start];
        swap(nums[start], nums[j]);
        if(j > k) return sort(nums, start, j - 1, k);
        else return sort(nums, j + 1, end, k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return sort(nums, 0, nums.size() - 1, k - 1);
    }
};
