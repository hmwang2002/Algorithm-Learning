#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for (auto &e : redEdges)
        {
            graph[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges)
        {
            graph[1][e[0]].push_back(e[1]);
        }
        vector<vector<int>> dis(2, vector<int>(n, INT_MAX));
        dis[0][0] = 0;
        dis[1][0] = 0;
        queue<pii> q;
        q.emplace(0, 0);
        q.emplace(0, 1);
        while (!q.empty())
        {
            auto [x, t] = q.front();
            q.pop();
            for (auto y : graph[1 - t][x])
            {
                if (dis[1 - t][y] != INT_MAX)
                {
                    continue;
                }
                dis[1 - t][y] = dis[t][x] + 1;
                q.emplace(y, 1 - t);
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = min(dis[0][i], dis[1][i]);
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};