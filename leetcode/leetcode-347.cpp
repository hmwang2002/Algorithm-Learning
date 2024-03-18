#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (const int &n : nums)
        {
            mp[n]++;
        }

        auto cmp = [&](const pair<int, int> &m, const pair<int, int> &n)
        {
            return m.second < n.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->first, it->second});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};