#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob1(vector<int> &nums, int start, int end)
    {
        int f1 = 0, f2 = 0;
        for (int i = start; i <= end; i++)
        {
            int tmp = f2;
            f2 = max(f2, f1 + nums[i]);
            f1 = tmp;
        }
        return f2;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        return max(nums[0] + rob1(nums, 2, n - 2), rob1(nums, 1, n - 1));
    }
};