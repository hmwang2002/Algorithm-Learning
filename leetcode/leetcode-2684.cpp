#include <bits/stdc++.h>

using namespace std;

auto _{[]() noexcept
       {
           std::ios::sync_with_stdio(false);
           std::cin.tie(nullptr);
           std::cout.tie(nullptr);
           return 0;
       }()};

class Solution
{
public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int j = n - 1; j > 0; j--)
        {
            for (int i = 0; i < m; i++)
            {
                if (i > 0 && grid[i][j] > grid[i - 1][j - 1])
                {
                    dp[i - 1][j - 1] = max(dp[i - 1][j - 1], dp[i][j] + 1);
                }
                if (i < m - 1 && grid[i][j] > grid[i + 1][j - 1])
                {
                    dp[i + 1][j - 1] = max(dp[i + 1][j - 1], dp[i][j] + 1);
                }
                if (grid[i][j] > grid[i][j - 1])
                {
                    dp[i][j - 1] = max(dp[i][j - 1], dp[i][j] + 1);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};