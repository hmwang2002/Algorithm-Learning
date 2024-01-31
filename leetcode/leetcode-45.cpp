#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int ans = 0;
        int end = 0; // 能跳的区间终点
        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end)
            {
                end = maxPos;
                ans++;
            }
            if (end >= nums.size() - 1)
                return ans;
        }
        return ans;
    }
};