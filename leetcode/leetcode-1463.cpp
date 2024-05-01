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
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j != 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k]);
                        if (k != 0)
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
                        }
                        if (k != n - 1)
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k + 1]);
                        }
                    }
                    if (j != n - 1)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k]);
                        if (k != 0)
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k - 1]);
                        }
                        if (k != n - 1)
                        {
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j + 1][k + 1]);
                        }
                    }
                    if (k != 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
                    }
                    if (k != n - 1)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k + 1]);
                    }
                    if (j == k)
                    {
                        dp[i][j][k] += grid[i][j];
                    }
                    else
                    {
                        dp[i][j][k] += grid[i][j] + grid[i][k];
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, *max_element(dp[m - 1][i].begin(), dp[m - 1][i].end()));
        }
        return ans;
    }
};