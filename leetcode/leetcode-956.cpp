#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int inf = 0x3f3f3f3f;

    int tallestBillboard(vector<int> &rods)
    {
        int n = rods.size(), md = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(n, vector<int>(md + 1, -1));
        function<int(int, int)> dfs = [&](int i, int d) -> int
        {
            if (d > md)
                return -inf;
            if (~dp[i][d])
                return dp[i][d];
            if (i == 0)
            {
                if (rods[i] == d)
                    return d;
                if (d == 0)
                    return 0;
                return -inf;
            }
            int res = dfs(i - 1, d);
            res = max(res, dfs(i - 1, d + rods[i]) + rods[i]);
            res = max(res, dfs(i - 1, abs(d - rods[i])) + rods[i]);

            return dp[i][d] = res;
        };

        return dfs(n - 1, 0) > 0 ? dfs(n - 1, 0) / 2 : 0;
    }
};