#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution
{
public:
    vector<vector<pii>> graph;
    vector<bool> vis;
    int ans = INT_MAX;

    void dfs(int u)
    {
        vis[u] = true;
        for (auto &e : graph[u])
        {
            // 因为要判断连通图权重最小的边，所以ans的计算放在if外面
            ans = min(ans, e.second);
            if (!vis[e.first])
            {
                dfs(e.first);
            }
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        graph.resize(n + 1);
        vis.resize(n + 1);
        for (vector<int> &e : roads)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        dfs(1);
        return ans;
    }
};

class Solution
{
public:
    vector<int> fa;
    vector<int> score;

    void init(int n)
    {
        fa.resize(n);
        score.resize(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void join(int x, int y, int dis)
    {
        int u = find(x), v = find(y);
        if (u == v)
        {
            score[u] = min(score[u], dis);
        }
        else
        {
            fa[v] = u;
            score[u] = min(min(score[u], score[v]), dis);
        }
    }

    int minScore(int n, vector<vector<int>> &roads)
    {
        init(n);
        for (auto &e : roads)
        {
            join(e[0] - 1, e[1] - 1, e[2]);
        }
        int x = find(n - 1);
        return score[x];
    }
};