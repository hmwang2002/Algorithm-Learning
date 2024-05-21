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
    vector<int> getSumAbsoluteDifferences(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 0; i < n; i++)
        {
            pre[i + 1] = pre[i] + nums[i];
        }
        vector<int> result(n);
        for (int i = 0; i < n; i++)
        {
            int left = i * nums[i] - pre[i];
            int right = pre[n] - pre[i] - nums[i] * (n - i);
            result[i] = left + right;
        }
        return result;
    }
};