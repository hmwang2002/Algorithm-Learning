#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;

int ans = 0;

void dfs(vector<vector<int>> &edges, vector<bool> &visited, int u)
{
    visited[u] = true;
    for (int v : edges[u])
    {
        if (!visited[v])
        {
            dfs(edges, visited, v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    vector<bool> visited(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int cnt = 0;
    unordered_set<int> se;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (cnt >= 2)
            {
                break;
            }
            dfs(edges, visited, i);
            if (cnt == 0)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (visited[j])
                    {
                        se.insert(j);
                    }
                }
            }
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    if (cnt > 2)
    {
        cout << 0 << endl;
    }
    else
    {
        ans = se.size() * (n - se.size());
        cout << ans << endl;
    }
}