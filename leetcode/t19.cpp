#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int res = INT_MAX, cur = 0;
        for (int l = 0, r = 0; r < nums.size(); r++)
        {
            cur += nums[r];
            if (cur >= target)
                res = min(res, r - l + 1);
            while (cur >= target)
            {
                cur -= nums[l++];
                if (cur >= target)
                    res = min(res, r - l + 1);
            }
        }
        return res != INT_MAX ? res : 0;
    }
};