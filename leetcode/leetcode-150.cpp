#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (string &s : tokens)
        {
            if (s == "+")
            {
                int m = stk.top();
                stk.pop();
                int n = stk.top();
                stk.pop();
                stk.push(n + m);
            }
            else if (s == "-")
            {
                int m = stk.top();
                stk.pop();
                int n = stk.top();
                stk.pop();
                stk.push(n - m);
            }
            else if (s == "*")
            {
                int m = stk.top();
                stk.pop();
                int n = stk.top();
                stk.pop();
                stk.push(n * m);
            }
            else if (s == "/")
            {
                int m = stk.top();
                stk.pop();
                int n = stk.top();
                stk.pop();
                stk.push(n / m);
            }
            else
            {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};