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
    bool hasValidPath(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if ((m + n) % 2 == 0 || grid[0][0] != '(' || grid[m - 1][n - 1] != ')')
            return false;
        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>((m + n + 1) / 2)));
        function<bool(int, int, int)> dfs = [&](int i, int j, int c) -> bool
        {
            if (c > m - i + n - j - 1)
                return false;
            if (i == m - 1 && j == n - 1)
                return c == 1;
            if (vis[i][j][c])
                return false;
            vis[i][j][c] = true;
            c += grid[i][j] == '(' ? 1 : -1;
            return c >= 0 && (i < m - 1 && dfs(i + 1, j, c) || (j < n - 1 && dfs(i, j + 1, c)));
        };
        return dfs(0, 0, 0);
    }
};