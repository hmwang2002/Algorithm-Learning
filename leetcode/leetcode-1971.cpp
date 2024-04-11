#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> fa;

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        fa.resize(n);
        for (int i = 0; i < n; i++)
            fa[i] = i;
        for (auto &vec : edges)
        {
            if (find(vec[0]) != find(vec[1]))
            {
                fa[find(vec[0])] = find(vec[1]);
            }
        }
        return find(source) == find(destination);
    }
};