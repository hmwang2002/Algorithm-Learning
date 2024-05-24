#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0) - x;
        if (sum < 0)
            return -1;
        else if (sum == 0)
            return n;
        int res = 0;
        for (int l = 0, r = 0, cur = 0; r < n; r++)
        {
            cur += nums[r];
            while (cur > sum)
            {
                cur -= nums[l++];
            }
            if (cur == sum)
                res = max(res, r - l + 1);
        }
        return res != 0 ? n - res : -1;
    }
};