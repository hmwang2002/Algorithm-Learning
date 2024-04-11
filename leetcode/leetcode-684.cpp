#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int n = 1005;
    vector<int> fa = vector<int>(n, 0);

    void init()
    {
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if(u == v)
            return;
        fa[v] = u;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        init();
        for(auto &vec : edges) {
            if(isSame(vec[0], vec[1]))
                return vec;
            else
                join(vec[0], vec[1]);
        }
        return {};
    }
};