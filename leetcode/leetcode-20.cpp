#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            char top = stk.empty() ? 0 : stk.top();
            if (c == ')')
            {
                if (top == '(')
                    stk.pop();
                else
                    return false;
            }
            else if (c == ']')
            {
                if (top == '[')
                    stk.pop();
                else
                    return false;
            }
            else if (c == '}')
            {
                if (top == '{')
                    stk.pop();
                else
                    return false;
            }
            else
            {
                stk.push(c);
            }
        }
        return stk.empty();
    }
};