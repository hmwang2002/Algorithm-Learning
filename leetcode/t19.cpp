#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

auto _{
    []() noexcept
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr), std::cout.tie(nullptr);
        return 0;
    }()};

using pii = pair<int, int>;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pii>> graph(n);
        for (auto &e : times)
        {
            graph[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        }
        vector<int> dis(n, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        dis[k - 1] = 0;
        pq.emplace(0, k - 1);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dx > dis[x])
            {
                continue;
            }
            for (auto &[y, dy] : graph[x])
            {
                int new_dis = dx + dy;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }
        int ans = *max_element(dis.begin(), dis.end());
        return ans == INT_MAX ? -1 : ans;
    }
};