#include <bits/stdc++.h>

using namespace std;

int R, C;
vector<vector<char>> board;
bool flag = true;
int cnt = 0;

bool check(int x, int y, int dirx, int diry)
{
    if (dirx != 0)
    {
        for (int i = x + dirx; i >= 0 && i < R; i += dirx)
        {
            if (board[i][y] != '.')
                return true;
        }
    }
    else
    {
        for (int j = y + diry; j >= 0 && j < C; j += diry)
        {
            if (board[x][j] != '.')
                return true;
        }
    }
    return false;
}

void dfs(int x, int y)
{
    for (int i = x - 1; i >= 0; i--)
    {
        if (board[i][y] != '.')
        {
            board[x][y] = 'U';
            cnt++;
            return;
        }
    }
    for (int i = x + 1; i < R; i++)
    {
        if (board[i][y] != '.')
        {
            board[x][y] = 'D';
            cnt++;
            return;
        }
    }
    for (int j = y + 1; j < C; j++)
    {
        if (board[x][j] != '.')
        {
            board[x][y] = 'R';
            cnt++;
            return;
        }
    }
    for (int j = y - 1; j >= 0; j--)
    {
        if (board[x][j] != '.')
        {
            board[x][y] = 'L';
            cnt++;
            return;
        }
    }
    flag = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> R >> C;
    board.resize(R);
    for (int i = 0; i < R; i++)
        board[i].resize(C);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] != '.')
            {
                int dx, dy;
                if (board[i][j] == 'U')
                {
                    dx = -1, dy = 0;
                }
                else if (board[i][j] == 'L')
                {
                    dx = 0, dy = -1;
                }
                else if (board[i][j] == 'R')
                {
                    dx = 0, dy = 1;
                }
                else
                {
                    dx = 1, dy = 0;
                }
                if (!check(i, j, dx, dy))
                {
                    dfs(i, j);
                    if (!flag)
                    {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
