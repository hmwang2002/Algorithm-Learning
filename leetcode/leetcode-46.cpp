#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> res;

    void backtracking(vector<int>& nums, int idx) {
        if(idx == nums.size() - 1) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size();i++){
            swap(nums[i], nums[idx]);
            backtracking(nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        backtracking(nums, 0);
        return res;
    }
};