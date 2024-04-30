#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        int sum = 0, res = 0;
        unordered_map<int, int> mp;
        for (int &x : nums)
        {
            mp[sum]++;
            sum += x;
            res += mp[sum - goal];
        }
        return res;
    }
};