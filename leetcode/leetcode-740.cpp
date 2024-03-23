#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
        {
            int tmp = second;
            second = max(second, first + nums[i]);
            first = tmp;
        }
        return second;
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        // 先记录存在哪些可能的取值，转换成打家劫舍问题
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            maxVal = max(maxVal, nums[i]);
        }
        vector<int> sum(maxVal + 1);
        for (int &val : nums)
        {
            sum[val] += val;
        }
        return rob(sum);
    }
};