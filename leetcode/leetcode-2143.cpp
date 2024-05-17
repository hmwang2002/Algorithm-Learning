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
    int minSwaps(vector<int> &nums)
    {
        int k = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                k++;
        }
        if (k == 0)
            return 0;
        int cur = 0;
        for (int i = 0; i < k; i++)
        {
            cur += (1 - nums[i]);
        }
        int ans = cur;
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] == 0)
                cur--;
            if (nums[(i + k - 1) % n] == 0)
                cur++;
            ans = min(ans, cur);
        }
        return ans;
    }
};