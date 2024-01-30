#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int farthest = 0;
        for (auto &trip : trips)
        {
            farthest = max(farthest, trip[2]);
        }
        vector<int> nums(farthest);

        for (auto &trip : trips)
        {
            nums[trip[1]] += trip[0];
            if (trip[2] < farthest)
            {
                nums[trip[2]] -= trip[0];
            }
        }
        if (nums[0] > capacity)
            return false;
        for (int i = 1; i < farthest; i++)
        {
            nums[i] += nums[i - 1];
            if (nums[i] > capacity)
                return false;
        }

        return true;
    }
};