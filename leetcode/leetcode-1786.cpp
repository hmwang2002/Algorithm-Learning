#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

class Solution
{
    vector<vector<pii>> graph;
    vector<int> dis;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    void dijkstra(int n)
    {
        dis[n] = 0;
        pq.emplace(0, n);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
                continue;
            for (auto &[y, w] : graph[x])
            {
                int new_dis = dx + w;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        graph.resize(n + 1);
        dis.resize(n + 1, INT_MAX);
        for (auto &e : edges)
        {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }
        dijkstra(n);
        vector<vector<int>> arr(n, vector<int>(2));
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = i + 1;
            arr[i][1] = dis[i + 1];
        }
        sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        vector<int> dp(n + 1);
        dp[n] = 1;
        for (int i = 0; i < n; i++)
        {
            int x = arr[i][0];
            for (auto &[y, w] : graph[x])
            {
                if (dis[x] < dis[y])
                {
                    dp[y] = (dp[y] + dp[x]) % 1000000007;
                }
            }
        }
        return dp[1];
    }
};