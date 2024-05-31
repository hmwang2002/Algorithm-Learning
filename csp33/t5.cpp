#include <bits/stdc++.h>

using namespace std;

int n, m, fi, di, op, x;
vector<vector<int>> f;
vector<int> d;
vector<bool> valid;

int dfs(int u)
{
    if (u == x)
        return 1;
    for (int v : f[u])
    {
        int ret = dfs(v);
        if (ret)
            return ret + 1;
    }
    return 0;
}

void merge()
{
    vector<int> ans;
    int newd = d[x];
    for (int v : f[x])
    {
        for (int v1 : f[v])
        {
            ans.push_back(v1);
        }
        newd += d[v];
        valid[v] = false;
    }
    f[x] = ans;
    d[x] = newd;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    f.resize(n + 1);
    d.resize(n + 1);
    valid.resize(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        cin >> fi;
        f[fi].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> di;
        d[i] = di;
    }
    while (m--)
    {
        cin >> op >> x;
        if (op == 1)
        {
            merge();
            cout << f[x].size() << " " << d[x] << endl;
        }
        else
        {
            if (!valid[x])
            {
                cout << 0 << endl;
                continue;
            }
            cout << dfs(1) << endl;
        }
    }
}