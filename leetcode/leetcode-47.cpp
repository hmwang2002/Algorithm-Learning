#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<int> visited;

    void backtrace(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
            {
                continue;
            }
            if (!visited[i])
            {
                visited[i] = true;
                path.push_back(nums[i]);
                backtrace(nums);
                visited[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        visited.resize(nums.size());
        backtrace(nums);
        return res;
    }
};