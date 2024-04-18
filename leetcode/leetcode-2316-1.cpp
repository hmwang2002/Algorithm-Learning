#include <bits/stdc++.h>

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
    vector<bool> vis;

    int dfs(vector<vector<int>> &graph, int u)
    {
        vis[u] = true;
        int cnt = 1;
        for (int &v : graph[u])
        {
            if (!vis[v])
            {
                cnt += dfs(graph, v);
            }
        }
        return cnt;
    }

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vis.resize(n);
        vector<vector<int>> graph(n);
        for (const auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                long long cnt = dfs(graph, i);
                res += cnt * (n - cnt);
            }
        }
        return res / 2;
    }
};