#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<bool>> visited;
    string s;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool backtrace(vector<vector<char>> &board, string &word, int i, int j, int index)
    {
        visited[i][j] = true;
        if (board[i][j] == word[index])
        {
            s.push_back(board[i][j]);
            if (s.size() == word.size())
                return true;
            for (int k = 0; k < 4; k++)
            {
                int newi = i + dir[k][0], newj = j + dir[k][1];
                if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size() && !visited[newi][newj])
                {
                    bool ret = backtrace(board, word, newi, newj, index + 1);
                    if (ret)
                    {
                        return true;
                    }
                }
            }
            visited[i][j] = false;
            s.pop_back();
            return false;
        }
        else
        {
            visited[i][j] = false;
            return false;
        }
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        visited = vector<vector<bool>>((int)board.size(), vector<bool>((int)board[0].size(), false));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                bool res = backtrace(board, word, i, j, 0);
                if (res)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    s.exist(board, word);
}