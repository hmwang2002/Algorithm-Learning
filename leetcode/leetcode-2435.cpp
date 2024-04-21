#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int MOD = 1000000007;

    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        int dp[m + 1][n + 1][k];
        memset(dp, 0, sizeof dp);
        dp[0][1][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int p = 0; p < k; p++)
                {
                    dp[i + 1][j + 1][(p + grid[i][j]) % k] = (dp[i][j + 1][p] + dp[i + 1][j][p]) % MOD;
                }
            }
        }
        return dp[m][n][0];
    }
};