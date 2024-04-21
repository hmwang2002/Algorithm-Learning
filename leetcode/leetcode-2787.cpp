#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        int MOD = 1e9 + 7;
        long p[n + 1];
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
            for (int j = 2; j <= x; j++)
            {
                p[i] *= i;
            }
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= p[i]; j--)
            {
                dp[j] = (dp[j] + dp[j - p[i]]) % MOD;
            }
        }
        return dp[n];
    }
};