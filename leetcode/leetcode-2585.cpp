#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;

    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int f[target + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (auto &p : types)
        {
            int count = p[0], marks = p[1];
            for (int j = target; j > 0; j--)
            {
                for (int k = 1; k <= min(count, j / marks); k++)
                {
                    f[j] = (f[j] + f[j - k * marks]) % MOD;
                }
            }
        }
        return f[target];
    }
};