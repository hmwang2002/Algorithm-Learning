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
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> res(n, -1);
        int div = 2 * k + 1;
        long long sum = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (i - 2 * k > 0)
                sum -= nums[i - 2 * k - 1];
            if (i - k < 0)
            {
                res[j++] = -1;
                continue;
            }
            if (i >= 2 * k)
            {
                res[j++] = sum / div;
            }
        }
        while (j < n)
        {
            res[j++] = -1;
        }
        return res;
    }
};