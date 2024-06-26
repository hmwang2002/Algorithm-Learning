#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 1; i <= n2; i++)
        {
            dp[0][i] = dp[0][i - 1] + 1;
        }
        for (int i = 1; i <= n1; i++)
        {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            dp[i + 1][0] = i + 1;
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = word1[i] == word2[j] ? dp[i][j] : min(dp[i][j + 1], min(dp[i + 1][j], dp[i][j])) + 1;
            }
        }
        return dp[n][m];
    }
};