#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     bool canPartition(vector<int> &nums)
//     {
//         int n = nums.size();
//         if (n < 2)
//             return false;
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int maxNum = *max_element(nums.begin(), nums.end());
//         if (sum & 1)
//         {
//             return false;
//         }
//         int target = sum / 2;
//         if (maxNum > target)
//         {
//             return false;
//         }
//         vector<bool> dp(target + 1);
//         dp[0] = true, dp[nums[0]] = true;
//         for (int i = 1; i < n; i++)
//         {
//             int x = nums[i];
//             for (int j = target; j >= x; j--)
//             {
//                 dp[j] = dp[j] | dp[j - x];
//             }
//         }
//         return dp[target];
//     }
// };

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        vector<int> dp(10001, 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 == 1)
            return false;
        int target = sum / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return target == dp[target];
    }
};