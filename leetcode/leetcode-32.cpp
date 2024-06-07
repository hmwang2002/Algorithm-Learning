#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        vector<int> dp(n);
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                {
                    dp[i] = (i >= 2) ? dp[i - 2] + 2 : 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0;
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                stk.pop();
                if (stk.empty())
                {
                    stk.push(i);
                }
                res = max(res, i - stk.top());
            }
            else
            {
                stk.push(i);
            }
        }
        return res;
    }
};