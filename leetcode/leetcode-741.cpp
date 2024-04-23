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
        int n = grid.size();
        vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MIN)));
        dp[2][1][1] = grid[0][0];
        for (int k = 3; k <= 2 * n; k++)
        {
            for (int i1 = 1; i1 <= n; i1++)
            {
                for (int i2 = 1; i2 <= n; i2++)
                {
                    int j1 = k - i1, j2 = k - i2;
                    if (j1 <= 0 || j1 > n || j2 <= 0 || j2 > n)
                        continue;
                    int a = grid[i1 - 1][j1 - 1], b = grid[i2 - 1][j2 - 1];
                    if (a == -1 || b == -1)
                        continue;
                    int t = max(max(dp[k - 1][i1 - 1][i2], dp[k - 1][i1][i2]), max(dp[k - 1][i1 - 1][i2 - 1], dp[k - 1][i1][i2 - 1])) + a;
                    if (i1 != i2)
                        t += b;
                    dp[k][i1][i2] = t;
                }
            }
        }
        return dp[2 * n][n][n] <= 0 ? 0 : dp[2 * n][n][n];
    }
};