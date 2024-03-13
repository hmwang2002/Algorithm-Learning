#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         int n = s.length();
//         if (n < 2)
//             return s;
//         vector<vector<bool>> dp(n, vector<bool>(n, 0));
//         for (int i = 0; i < n; i++)
//         {
//             dp[i][i] = true;
//         }
//         int maxLen = 1;
//         int begin = 0;
//         for (int L = 2; L <= n; L++)
//         {
//             for (int i = 0; i < n; i++)
//             {
//                 int j = i + L - 1;
//                 if (j >= n)
//                     break;
//                 if (s[i] != s[j])
//                     dp[i][j] = false;
//                 else
//                 {
//                     if (j - i < 2)
//                     {
//                         dp[i][j] = true;
//                     }
//                     else
//                     {
//                         dp[i][j] = dp[i + 1][j - 1];
//                     }
//                 }
//                 if (dp[i][j] && j - i + 1 > maxLen)
//                 {
//                     begin = i;
//                     maxLen = j - i + 1;
//                 }
//             }
//         }
//         return s.substr(begin, maxLen);
//     }
// };