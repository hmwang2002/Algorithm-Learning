#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        auto cmp = [&](const pair<int, int> &a, const pair<int, int> &b) -> bool
        {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        vector<vector<int>> ans;
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (int i = 0; i < min(m, k); i++)
        {
            q.emplace(i, 0);
        }
        while (k-- > 0 && !q.empty())
        {
            auto [x, y] = q.top();
            q.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y + 1 < n)
            {
                q.emplace(x, y + 1);
            }
        }
        return ans;
    }
};