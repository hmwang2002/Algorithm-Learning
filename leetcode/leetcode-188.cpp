#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(k + 1, vector<int>(2));
        for (int i = 0; i <= k; i++)
        {
            dp[i][0] = -prices[0];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = k; j >= 1; j--)
            {
                dp[j][0] = max(dp[j][0], dp[j - 1][1] - prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] + prices[i]);
            }
        }
        return dp[k][1];
    }
};