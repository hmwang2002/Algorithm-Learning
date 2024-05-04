#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};

class Solution
{
public:
    int longestCommonSubsequence(string s, string t)
    {
        int m = t.length(), f[m + 1];
        memset(f, 0, sizeof(f));
        for (char x : s)
            for (int j = 0, pre = 0; j < m; ++j)
            {
                int tmp = f[j + 1];
                f[j + 1] = x == t[j] ? pre + 1 : max(f[j + 1], f[j]);
                pre = tmp;
            }
        return f[m];
    }
};