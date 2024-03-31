#include <bits/stdc++.h>

using namespace std;

int n, m;

int dir_x[4] = {-1, 0, 1, 0};
int dir_y[4] = {0, -1, 0, 1};

string s;
string target = "tencent";

vector<string> matrix;

int ans = 0;

void dfs(int i, int j, string &path)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return;
    }
    int len = path.size();
    if (len > 7)
    {
        return;
    }
    if (matrix[i][j] != target[len])
        return;
    path.push_back(matrix[i][j]);
    if (path == target)
    {
        ans++;
        path.pop_back();
        return;
    }
    for (int k = 0; k < 4; k++)
    {
        dfs(i + dir_x[k], j + dir_y[k], path);
    }
    path.pop_back();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        matrix.push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 't')
            {
                string p = "";
                dfs(i, j, p);
            }
        }
    }
    cout << ans << endl;
}