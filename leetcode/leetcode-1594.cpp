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
    const static int mod = 1e9 + 7;

    int maxProductPath(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp_max(m, vector<long long>(n));
        vector<vector<long long>> dp_min(m, vector<long long>(n));
        dp_max[0][0] = grid[0][0], dp_min[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
        {
            dp_max[0][i] = dp_max[0][i - 1] * grid[0][i] % mod;
            dp_min[0][i] = dp_min[0][i - 1] * grid[0][i] % mod;
        }
        for (int i = 1; i < m; i++)
        {
            dp_max[i][0] = dp_max[i - 1][0] * grid[i][0] % mod;
            dp_min[i][0] = dp_min[i - 1][0] * grid[i][0] % mod;
            for (int j = 1; j < n; j++)
            {
                dp_max[i][j] = max(dp_max[i - 1][j] * grid[i][j], max(dp_min[i - 1][j] * grid[i][j], max(dp_max[i][j - 1] * grid[i][j], dp_min[i][j - 1] * grid[i][j]))) % mod;
                dp_min[i][j] = min(dp_max[i - 1][j] * grid[i][j], min(dp_min[i - 1][j] * grid[i][j], min(dp_max[i][j - 1] * grid[i][j], dp_min[i][j - 1] * grid[i][j]))) % mod;
            }
        }
        return dp_max[m - 1][n - 1] < 0 ? -1 : dp_max[m - 1][n - 1] % mod;
    }
};