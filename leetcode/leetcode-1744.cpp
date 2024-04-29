#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        int n = candiesCount.size();
        vector<long long> pre(n + 1);
        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] + candiesCount[i - 1];
        }
        vector<bool> res;
        for (auto &q : queries)
        {
            int type = q[0] + 1, day = q[1], maxConsumption = q[2];
            long long l = day + 1, r = (long long)(day + 1) * maxConsumption;
            long long minCandies = pre[type - 1] + 1, maxCandies = pre[type];
            res.push_back(!(l > maxCandies || r < minCandies));
        }
        return res;
    }
};