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
    vector<vector<int>> cache;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int i, int j, vector<vector<int>> &matrix)
    {
        if (cache[i][j] != -1)
        {
            return cache[i][j];
        }
        int res = 1;
        for (int x = 0; x < 4; x++)
        {
            int new_i = i + dir[x][0], new_j = j + dir[x][1];
            if (new_i < 0 || new_i >= matrix.size() || new_j < 0 || new_j >= matrix[0].size() || matrix[new_i][new_j] <= matrix[i][j])
            {
                continue;
            }
            res = max(res, dfs(new_i, new_j, matrix) + 1);
        }
        cache[i][j] = res;
        return res;
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        cache.resize(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(i, j, matrix));
            }
        }
        return ans;
    }
};