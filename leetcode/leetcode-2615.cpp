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
    vector<long long> distance(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++)
        {
            groups[nums[i]].push_back(i);
        }

        vector<long long> ans(n);
        long long s[n + 1];
        s[0] = 0;
        for (auto &[_, a] : groups)
        {
            int m = a.size();
            for (int i = 0; i < m; i++)
            {
                s[i + 1] = s[i] + a[i];
            }
            for (int i = 0; i < m; i++)
            {
                long long target = a[i];
                long long left = target * i - s[i];
                long long right = s[m] - s[i] - (m - i) * target;
                ans[target] = left + right;
            }
        }
        return ans;
    }
};