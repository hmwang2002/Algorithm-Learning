#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int coinChange(vector<int> &coins, int amount)
//     {
//         int n = coins.size();
//         vector<int> dp(amount + 1, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i <= amount; i++)
//         {
//             for (int j = n - 1; j >= 0; j--)
//             {
//                 if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
//                     dp[i] = min(dp[i], dp[i - coins[j]] + 1);
//             }
//         }
//         return dp[amount] != INT_MAX ? dp[amount] : -1;
//     }
// };

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<long long> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (auto coin : coins)
        {
            for (int i = coin; i <= amount; ++i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};