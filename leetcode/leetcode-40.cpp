#include <bits/stdc++.h>

using namespace std;

class Solution
{
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
        {
            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            if (i > index && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            v.push_back(candidates[i]);
            backtrace(candidates, target, i + 1, sum + candidates[i]);
            v.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0, 0);
        return res;
    }
};