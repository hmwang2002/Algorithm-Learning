#include <bits/stdc++.h>

using namespace std;

const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INF));
        dist[0][0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.emplace(0, 0);
        vector<bool> vis(m * n);
        while (!pq.empty())
        {
            auto [dx, x] = pq.top();
            pq.pop();
            if (vis[x])
                continue;
            vis[x] = true;
            int i = x / n, j = x % n;
            for (int k = 0; k < 4; k++)
            {
                int ni = i + dirx[k];
                int nj = j + diry[k];
                if (ni < 0 || ni >= m || nj < 0 || nj >= n)
                    continue;
                int nd = dx + (grid[i][j] == k + 1 ? 0 : 1);
                if (nd < dist[ni][nj])
                {
                    dist[ni][nj] = nd;
                    pq.emplace(nd, ni * n + nj);
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};