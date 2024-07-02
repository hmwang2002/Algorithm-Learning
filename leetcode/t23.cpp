#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<vector<pii>> edges(n);
        vector<int> dis(n, 0x3f3f3f3f);
        for (auto &e : times)
        {
            edges[e[0] - 1].emplace_back(e[1] - 1, e[2]);
        }
        priority_queue<pii, vector<pii>, less<pii>> pq;
        pq.emplace(0, k - 1);
        dis[k - 1] = 0;
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (dis[x] < dx)
            {
                continue;
            }
            for (auto &[y, dy] : edges[x])
            {
                int new_dis = dx + dy;
                if (new_dis < dis[y])
                {
                    dis[y] = new_dis;
                    pq.emplace(new_dis, y);
                }
            }
        }
        int res = *max_element(dis.begin(), dis.end());
        return res != 0x3f3f3f3f ? res : -1;
    }
};