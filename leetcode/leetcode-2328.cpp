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
    static constexpr int MOD = 1e9 + 7;
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> cache;

    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        if (cache[i][j] != -1)
            return cache[i][j];
        int res = 1;
        for (int k = 0; k < 4; k++)
        {
            int newi = i + dir[k][0], newj = j + dir[k][1];
            if (newi < 0 || newi >= grid.size() || newj < 0 || newj >= grid[0].size())
                continue;
            if (grid[i][j] < grid[newi][newj])
            {
                res = (res + dfs(newi, newj, grid)) % MOD;
            }
        }
        cache[i][j] = res;
        return res;
    }

    int countPaths(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        cache.resize(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = (ans + dfs(i, j, grid)) % MOD;
            }
        }
        return ans;
    }
};