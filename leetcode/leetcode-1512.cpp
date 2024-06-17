#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int res = 0;
        for (int &x : nums)
        {
            mp[x]++;
            res += mp[x] - 1;
        }
        return res;
    }
};