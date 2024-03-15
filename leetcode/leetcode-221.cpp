#include <bits/stdc++.h>

using namespace std;

// class Solution
// {
// public:
//     int maximalSquare(vector<vector<char>> &matrix)
//     {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//         for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 dp[i][j] = matrix[i - 1][j - 1] - '0' + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//             }
//         }
//         int k = min(m, n);
//         for (int i = k; i >= 1; i--)
//         {
//             for (int j = i; j <= m; j++)
//             {
//                 for (int h = i; h <= n; h++)
//                 {
//                     if (i * i == dp[j][h] - dp[j - i][h] - dp[j][h - i] + dp[j - i][h - i])
//                     {
//                         return i * i;
//                     }
//                 }
//             }
//         }
//         return 0;
//     }
// };

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        int maxSide = 0;
        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(columns));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    maxSide = max(maxSide, dp[i][j]);
                }
            }
        }
        int maxSquare = maxSide * maxSide;
        return maxSquare;
    }
};