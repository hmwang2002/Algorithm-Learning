#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int dir_x[4] = {-1, 0, 1, 0};
    int dir_y[4] = {0, 1, 0, -1};
    vector<vector<bool>> visited;

    bool backtrace(vector<vector<char>> &board, string &word, int index, int i, int j)
    {
        if (index == word.size())
            return true;
        bool res = false;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dir_x[k], y = j + dir_y[k];
            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                continue;
            if (!visited[x][y] && board[x][y] == word[index])
            {
                visited[x][y] = true;
                res |= backtrace(board, word, index + 1, x, y);
                visited[x][y] = false;
            }
            if (res)
                return res;
        }
        return res;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    bool res = backtrace(board, word, 1, i, j);
                    visited[i][j] = false;
                    if (res)
                        return true;
                }
            }
        }
        return false;
    }
};