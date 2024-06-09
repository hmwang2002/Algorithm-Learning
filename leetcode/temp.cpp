#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int cnt = 0, end = 0, maxPos = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end)
            {
                end = maxPos;
                cnt++;
            }
            if (end >= nums.size() - 1)
            {
                return cnt;
            }
        }
        return cnt;
    }
};