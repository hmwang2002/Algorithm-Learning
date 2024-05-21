#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> se;
        int res = 0, cur = 0, l = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cur += nums[i];
            while (se.count(nums[i]))
            {
                cur -= nums[l];
                se.erase(nums[l]);
                l++;
            }
            se.insert(nums[i]);
            res = max(res, cur);
        }
        return res;
    }
};