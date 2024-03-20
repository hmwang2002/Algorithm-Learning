#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int pre = 0;
        for (int i = 0; i < nums.size(); i++) {
            pre += nums[i];
            if(mp.count(pre - k)) {
                ans += mp[pre - k];
            }
            mp[pre]++;
        }
        return ans;
    }
};