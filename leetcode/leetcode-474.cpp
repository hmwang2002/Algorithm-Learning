#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (const string &s : strs)
        {
            int cnt0 = 0, cnt1 = 0;
            for (char c : s)
            {
                if (c == '0')
                    cnt0 += 1;
                else
                    cnt1 += 1;
            }
            for (int i = m; i >= cnt0; i--)
            {
                for (int j = n; j >= cnt1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1);
                }
            }
        }
        return dp[m][n];
    }
};