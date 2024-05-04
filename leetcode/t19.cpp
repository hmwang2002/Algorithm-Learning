#include <bits/stdc++.h>
#include "datastructure.h"

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
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i + 1 != nums[i])
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};