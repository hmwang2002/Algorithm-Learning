#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int k = abs(nums[i]);
            if (nums[k] < 0)
                return k;
            nums[k] = -nums[k];
        }
        return -1;
    }
};