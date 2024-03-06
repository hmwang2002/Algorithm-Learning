#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int n, m;

public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != 'O')
            return;
        board[i][j] = 'A';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }

    void solve(vector<vector<char>> &board)
    {
        n = board.size();
        if (n == 0)
            return;
        m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, m - 1);
        }
        for (int i = 1; i < m; i++)
        {
            dfs(board, 0, i);
            dfs(board, n - 1, i);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'A')
                {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};