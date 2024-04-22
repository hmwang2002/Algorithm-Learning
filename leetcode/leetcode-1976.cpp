#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        vector<vector<pii>> graph(n);
        for (auto &e : roads)
        {
            graph[e[0]].emplace_back(e[1], e[2]);
            graph[e[1]].emplace_back(e[0], e[2]);
        }
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        vector<int> dp(n);
        dp[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, 0);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
                continue;
            if (x == n - 1)
                return dp[n - 1];
            for (auto &[y, dy] : graph[x])
            {
                long long new_dis = dx + dy;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                    dp[y] = dp[x];
                }
                else if (new_dis == dis[y])
                {
                    dp[y] = (dp[y] + dp[x]) % 1000000007;
                }
            }
        }
        return dp[n - 1];
    }
};