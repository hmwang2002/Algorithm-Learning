#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtrace(vector<int> &nums, int index)
    {
        if (index == nums.size())
        {
            res.push_back(path);
            return;
        }
        path.push_back(nums[index]);
        backtrace(nums, index + 1);
        path.pop_back();
        backtrace(nums, index + 1);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        backtrace(nums, 0);
        return res;
    }
};