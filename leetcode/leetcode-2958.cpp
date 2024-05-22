#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int res = 0, l = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            while (mp[nums[i]] > k)
            {
                mp[nums[l++]]--;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};