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
    int findMin(vector<vector<int>> &grid, vector<vector<int>> &dp, vector<vector<int>> &moveCost, int lastRow, int j, int k)
    {
        int n = dp[0].size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            res = min(res, dp[lastRow][i] + moveCost[grid[lastRow][i]][j]);
        }
        return res + k;
    }

    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i][j] = findMin(grid, dp, moveCost, i - 1, j, grid[i][j]);
            }
        }
        return *min_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};