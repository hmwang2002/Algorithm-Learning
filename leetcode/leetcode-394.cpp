#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        string res;
        int n;
        stack<pair<int, string>> stk;
        for (char c : s)
        {
            if (c == '[')
            {
                stk.emplace(n, res);
                res = "";
                n = 0;
            }
            else if (c == ']')
            {
                string tmp = "";
                for (int i = 0; i < stk.top().first; i++)
                {
                    tmp += res;
                }
                res = stk.top().second + tmp;
                stk.pop();
            }
            else if (c >= '0' && c <= '9')
            {
                n = n * 10 + c - '0';
            }
            else
            {
                res += c;
            }
        }
        return res;
    }
};