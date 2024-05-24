#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            pos[x].push_back(i - pos[x].size());
        }
        int ans = 0;
        for (auto &p : pos)
        {
            int l = 0;
            for (int r = 0; r < p.size(); r++)
            {
                while (p[r] - p[l] > k)
                {
                    l++;
                }
                ans = max(ans, r - l + 1);
            }
        }
        return ans;
    }
};