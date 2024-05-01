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
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
        {
            sum += nums[i - 1];
            if (mp.count(sum % k))
            {
                int j = mp[sum % k];
                if (i - j >= 2)
                {
                    return true;
                }
                else
                {
                    continue;
                }
            }
            mp[sum % k] = i;
        }
        return false;
    }
};