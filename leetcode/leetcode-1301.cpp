#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

using PII = pair<int, int>;

class Solution
{
public:
    const static int mod = (int)1e9 + 7;

    void update(vector<vector<PII>> &dp, int n, int x, int y, int u, int v)
    {
        if (u >= n || v >= n || dp[u][v].first == -1)
            return;
        if (dp[u][v].first > dp[x][y].first)
        {
            dp[x][y] = dp[u][v];
        }
        else if (dp[u][v].first == dp[x][y].first)
        {
            dp[x][y].second += dp[u][v].second;
            dp[x][y].second %= mod;
        }
    }

    vector<int> pathsWithMaxScore(vector<string> &board)
    {
        int n = board.size();
        vector<vector<PII>> dp(n, vector<PII>(n, {-1, 0}));
        dp[n - 1][n - 1] = {0, 1};
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (!(i == n - 1 && j == n - 1) && board[i][j] != 'X')
                {
                    update(dp, n, i, j, i + 1, j);
                    update(dp, n, i, j, i, j + 1);
                    update(dp, n, i, j, i + 1, j + 1);
                    if (dp[i][j].first != -1)
                    {
                        dp[i][j].first += (board[i][j] == 'E' ? 0 : board[i][j] - '0');
                    }
                }
            }
        }
        return dp[0][0].first == -1 ? vector<int>{0, 0} : vector<int>{dp[0][0].first, dp[0][0].second};
    }
};