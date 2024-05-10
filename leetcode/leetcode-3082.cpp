#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;
    int sumOfPower(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(k + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = k; j >= nums[i]; j--)
            {
                for (int c = i + 1; c > 0; c--)
                {
                    dp[j][c] = (dp[j][c] + dp[j - nums[i]][c - 1]) % MOD;
                }
            }
        }
        int ans = 0;
        int pow2 = 1;
        for (int i = n; i > 0; i--)
        {
            ans = (ans + (long long)dp[k][i] * pow2) % MOD;
            pow2 = pow2 * 2 % MOD;
        }
        return ans;
    }
};