#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

class Solution
{
public:
    int electricCarPlan(vector<vector<int>> &paths, int cnt, int start, int end, vector<int> &charge)
    {
        int n = charge.size();
        vector<vector<int>> dis(n, vector<int>(cnt + 1, INF));
        dis[start][0] = 0;

        vector<vector<pair<int, int>>> graph(n);
        for (auto &path : paths)
        {
            int u = path[0], v = path[1], w = path[2];
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, start, 0);

        while (!pq.empty())
        {
            auto [t, u, c] = pq.top();
            pq.pop();
            if (t > dis[u][c])
                continue;
            if (u == end)
                return t;

            // 当前电不满，充电一分钟，状态变为(u,c+1)
            if (c < cnt)
            {
                int nt = t + charge[u];
                if (nt < dis[u][c + 1])
                {
                    dis[u][c + 1] = nt;
                    pq.emplace(nt, u, c + 1);
                }
            }

            // 如果一条边(u,v,w)能走，尝试走这条边，状态变为(v,c-w)
            for (auto [v, w] : graph[u])
            {
                if (c >= w && t + w < dis[v][c - w])
                {
                    dis[v][c - w] = t + w;
                    pq.emplace(t + w, v, c - w);
                }
            }
        }

        return -1;
    }
};