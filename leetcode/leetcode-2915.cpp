#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(target + 1, INT_MIN);
        dp[0] = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s = min(s + nums[i], target);
            for (int j = s; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + 1);
            }
        }
        return dp[target] > 0 ? dp[target] : -1;
    }
};