#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;

    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }
        int len = group.size();
        for (int i = 1; i <= len; i++)
        {
            int members = group[i - 1], earn = profit[i - 1];
            for (int j = n; j >= members; j--)
            {
                for (int k = minProfit; k >= 0; k--)
                {
                    dp[j][k] = (dp[j][k] + dp[j - members][max(0, k - earn)]) % MOD;
                }
            }
        }
        return dp[n][minProfit];
    }
};
