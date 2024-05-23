#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int l = 0, r = 0, or_ = 0; r < n; r++)
        {
            while (or_ & nums[r])
            {
                or_ ^= nums[l++];
            }
            or_ |= nums[r];
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};