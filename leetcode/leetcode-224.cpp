#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        stack<char> stk;
        int ans = 0, op = 1;
        long long num = 0;
        stk.push(op);

        for (char c : s)
        {
            if (c == ' ')
                continue;
            else if (c >= '0')
                num = num * 10 + c - '0';
            else
            {
                ans += op * num;
                num = 0;

                if (c == '+')
                    op = stk.top();
                else if (c == '-')
                    op = -stk.top();
                else if (c == '(')
                {
                    stk.push(op); // 将括号前符号存入栈
                }
                else
                {
                    stk.pop();
                }
            }
        }
        return ans + op * num;
    }
};