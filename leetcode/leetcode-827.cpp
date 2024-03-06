#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> areas;

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return 0;
        if (grid[i][j] != 1)
            return 0;
        grid[i][j] = areas.size() + 2;
        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }

    int calNewArea(vector<vector<int>> &grid, int i, int j)
    {
        int res = 1;
        unordered_map<int, int> mp;
        if (i - 1 >= 0 && grid[i - 1][j] > 1)
        {
            res += areas[grid[i - 1][j] - 2];
            mp[grid[i - 1][j] - 2] = areas[grid[i - 1][j] - 2];
        }
        if (i + 1 < grid.size() && grid[i + 1][j] > 1)
        {
            if (!mp.count(grid[i + 1][j] - 2))
            {
                res += areas[grid[i + 1][j] - 2];
                mp[grid[i + 1][j] - 2] = areas[grid[i + 1][j] - 2];
            }
        }
        if (j - 1 >= 0 && grid[i][j - 1] > 1)
        {
            if (!mp.count(grid[i][j - 1] - 2))
            {
                res += areas[grid[i][j - 1] - 2];
                mp[grid[i][j - 1] - 2] = areas[grid[i][j - 1] - 2];
            }
        }
        if (j + 1 < grid[0].size() && grid[i][j + 1] > 1)
        {
            if (!mp.count(grid[i][j + 1] - 2))
            {
                res += areas[grid[i][j + 1] - 2];
                mp[grid[i][j + 1] - 2] = areas[grid[i][j + 1] - 2];
            }
        }
        return res;
    }

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    areas.push_back(dfs(grid, i, j));
                }
            }
        }
        int ans = areas.size() > 0 ? areas[0] : 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    ans = max(ans, calNewArea(grid, i, j));
                }
            }
        }
        return ans;
    }
};