#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         if (n < 2)
//         {
//             return 0;
//         }

//         // dp[i][0]: 手上持有股票的最大收益
//         // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
//         // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
//         vector<vector<int>> dp(n, vector<int>(3));
//         dp[0][0] = -prices[0];
//         for (int i = 1; i < n; i++)
//         {
//             dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
//             dp[i][1] = dp[i - 1][0] + prices[i];
//             dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
//         }
//         return max(dp[n - 1][1], dp[n - 1][2]);
//     }
// };

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; i++)
        {
            int newf0 = max(f0, f2 - prices[i]);
            int newf1 = f0 + prices[i];
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1, f2);
    }
};