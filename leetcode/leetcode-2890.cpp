#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pre(n + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
        vector<int> ans(queries.size());
        int i = 0;
        for (int &q : queries)
        {
            ans[i++] = upper_bound(pre.begin(), pre.end(), q) - pre.begin() - 1;
        }
        return ans;
    }
};