#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jewelleryValue(vector<vector<int>> &frame)
    {
        if(frame.size() == 0)
            return 0;
        int m = frame.size(), n = frame[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + frame[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};