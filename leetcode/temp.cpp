#include <bits/stdc++.h>
#include "datastructure.h"

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else
            {
                if (stk.empty())
                    return false;
                if (c == ')' && stk.top() != '(')
                    return false;
                if (c == ']' && stk.top() != '[')
                    return false;
                if (c == '}' && stk.top() != '{')
                    return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};