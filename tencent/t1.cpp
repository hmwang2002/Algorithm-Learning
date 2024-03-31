#include <bits/stdc++.h>

using namespace std;

int n, m;

int u, v;
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<pair<int, bool>>> edges(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> c;
        if (c == 'R')
        {
            edges[u].push_back({v, true});
            edges[v].push_back({u, true});
        }
        else
        {
            edges[u].push_back({v, false});
            edges[v].push_back({u, false});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool f = true;
        for (int j = 0; j < edges[i].size(); j++)
        {
            if (edges[i][j].second == false)
            {
                f = false;
                break;
            }
        }
        if (f)
            ans++;
    }
    cout << ans << endl;
}