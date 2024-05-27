#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long countGood(vector<int> &nums, int k)
    {
        long long ans = 0;
        unordered_map<int, int> mp;
        int l = 0, cnt = 0;
        for (int r = 0; r < nums.size(); r++)
        {
            cnt += mp[nums[r]];
            mp[nums[r]]++;
            while (cnt - mp[nums[l]] + 1 >= k)
            {
                cnt -= --mp[nums[l]];
                l++;
            }
            if (cnt >= k)
                ans += l + 1;
        }
        return ans;
    }
};