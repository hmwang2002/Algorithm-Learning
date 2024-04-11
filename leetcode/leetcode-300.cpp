#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int lengthOfLIS(vector<int> &nums)
//     {
//         int n = nums.size();
//         vector<int> dp(n);
//         dp[0] = 1;
//         int ans = 1;
//         for (int i = 1; i < n; i++)
//         {
//             dp[i] = 1;
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[j] < nums[i])
//                     dp[i] = max(dp[i], dp[j] + 1);
//             }
//             ans = max(dp[i], ans);
//         }
//         return ans;
//     }
// };

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> d;
        for (int x : nums)
        {
            auto it = lower_bound(d.begin(), d.end(), x);
            if (it == d.end())
            {
                d.push_back(x);
            }
            else
            {
                *it = x;
            }
        }
        return d.size();
    }
};