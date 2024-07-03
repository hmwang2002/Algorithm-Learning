#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0), std::cout.tie(0);
    }};

class Solution
{
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> f(target + 1, INT_MIN);
        f[0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = target; j >= nums[i]; j--)
            {
                f[j] = max(f[j], f[j - nums[i]] + 1);
            }
        }
        return f[target] <= 0 ? -1 : f[target];
    }
};