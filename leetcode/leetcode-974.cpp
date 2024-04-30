#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            int mod = (sum % k + k) % k;
            if (mp.count(mod))
            {
                res += mp[mod];
            }
            mp[mod]++;
        }
        return res;
    }
};