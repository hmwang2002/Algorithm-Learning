#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 二进制枚举 + floyd
 * 
 */
class Solution
{
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads)
    {
        vector<vector<int>> g(n, vector<int>(n, 0x3f3f3f3f));
        for (auto &e : roads)
        {
            g[e[0]][e[1]] = min(g[e[0]][e[1]], e[2]);
            g[e[1]][e[0]] = min(g[e[1]][e[0]], e[2]);
        }
        for (int i = 0; i < n; i++)
        {
            g[i][i] = 0;
        }

        vector<vector<int>> f(n);
        auto check = [&](int s) -> bool
        {
            for (int i = 0; i < n; i++)
            {
                if ((s >> i) & 1)
                {
                    f[i] = g[i];
                }
            }

            for (int k = 0; k < n; k++)
            {
                if (((s >> k) & 1) == 0)
                    continue;
                for (int i = 0; i < n; i++)
                {
                    if (((s >> i) & 1) == 0)
                        continue;
                    for (int j = 0; j < n; j++)
                    {
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (((s >> i) & 1) == 0)
                    continue;
                for (int j = 0; j < n; j++)
                {
                    if ((s >> j) & 1 && f[i][j] > maxDistance)
                    {
                        return false;
                    }
                }
            }
            return true;
        };

        int ans = 0;
        for (int s = 0; s < (1 << n); s++)
        {
            ans += check(s);
        }
        return ans;
    }
};