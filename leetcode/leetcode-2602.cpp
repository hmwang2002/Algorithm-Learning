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
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long sum[n + 1];
        sum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + nums[i];
        }
        int m = queries.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; i++)
        {
            int q = queries[i];
            long long j = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long left = q * j - sum[j];
            long long right = sum[n] - sum[j] - q * (n - j);
            ans[i] = left + right;
        }
        return ans;
    }
};