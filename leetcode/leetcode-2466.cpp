#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one)
    {
        int ans = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % mod;
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % mod;
            if(i >= low)
                ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};