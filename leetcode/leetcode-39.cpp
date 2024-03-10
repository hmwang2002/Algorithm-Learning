#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> v;

    void backtrace(vector<int> &candidates, int target, int index, int sum)
    {
        if (sum == target)
        {
            res.push_back(v);
            return;
        }
        if (sum > target)
            return;
        for (int i = index; i < candidates.size(); i++)
        {
            v.push_back(candidates[i]);
            backtrace(candidates, target, i, sum + candidates[i]);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtrace(candidates, target, 0, 0);
        return res;
    }
};