#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        int cnt[m][n];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int k = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x < 0 || x >= m || y < 0 || y >= n || (x == i && y == j))
                            continue;
                        else if (board[x][y] == 1)
                            k++;
                    }
                }
                cnt[i][j] = k;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cnt[i][j] < 2)
                    board[i][j] = 0;
                else if (cnt[i][j] == 3)
                    board[i][j] = 1;
                else if (cnt[i][j] > 3)
                    board[i][j] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> vec = {{0, 1, 0},
                               {0, 0, 1},
                               {1, 1, 1},
                               {0, 0, 0}};
    Solution s;
    s.gameOfLife(vec);
}