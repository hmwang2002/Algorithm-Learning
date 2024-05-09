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
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
        for (int i = 1; i < m; i++)
        {
            long long maxL = LONG_MIN, maxR = LONG_MIN;
            vector<long long> temp = dp;
            for (int j = 0; j < n; j++)
            {
                maxL = max(maxL, temp[j] + j);
                dp[j] = points[i][j] - j + maxL;
            }
            for (int j = n - 1; j >= 0; j--)
            {
                maxR = max(maxR, temp[j] - j);
                dp[j] = max(dp[j], points[i][j] + j + maxR);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};