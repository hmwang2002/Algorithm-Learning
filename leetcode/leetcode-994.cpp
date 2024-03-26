#include <bits/stdc++.h>

using namespace std;

// dfs
// class Solution
// {
// public:
//     void dfs(vector<vector<int>> &grid, int i, int j)
//     {
//         if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
//         {
//             return;
//         }
//         grid[i][j] = 3;
//     }

//     int check(vector<vector<int>> &grid)
//     {
//         int left = 0;
//         for (int i = 0; i < grid.size(); i++)
//         {
//             for (int j = 0; j < grid[0].size(); j++)
//             {
//                 if (grid[i][j] == 1)
//                     left++;
//                 else if(grid[i][j] == 3) {
//                     grid[i][j] = 2;
//                 }
//             }
//         }
//         return left;
//     }

//     int orangesRotting(vector<vector<int>> &grid)
//     {
//         int cnt = 0;
//         int left = check(grid);
//         if (left == 0)
//             return 0;
//         while (1)
//         {
//             for (int i = 0; i < grid.size(); i++)
//             {
//                 for (int j = 0; j < grid[0].size(); j++)
//                 {
//                     if (grid[i][j] == 2)
//                     {
//                         dfs(grid, i - 1, j);
//                         dfs(grid, i + 1, j);
//                         dfs(grid, i, j - 1);
//                         dfs(grid, i, j + 1);
//                     }
//                 }
//             }
//             cnt++;
//             int l = check(grid);
//             if (l == 0)
//             {
//                 break;
//             }
//             if (left == l)
//             {
//                 return -1;
//             }
//             else
//             {
//                 left = l;
//             }
//         }
//         return cnt;
//     }
// };

class Solution
{
    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, -1, 0, 1};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size(), ans = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                }
                else if (grid[i][j] == 1)
                {
                    cnt++;
                }
            }
        }
        while (!q.empty())
        {
            int k = q.size();
            for (int j = 0; j < k; j++)
            {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++)
                {
                    int tx = p.first + dir_x[i];
                    int ty = p.second + dir_y[i];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == 1)
                    {
                        grid[tx][ty] = 2;
                        cnt--;
                        q.emplace(tx, ty);
                    }
                }
            }
            if (!q.empty())
            {
                ans++;
            }
        }
        return cnt ? -1 : ans;
    }
};