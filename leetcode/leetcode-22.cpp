#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<string> res;
    string s;

    void backtrace(int l, int r)
    {
        if (l < 0 || r < 0 || l > r)
            return;
        if (l == 0 && r == 0)
        {
            res.push_back(s);
        }

        if (l > 0)
        {
            s.push_back('(');
            backtrace(l - 1, r);
            s.pop_back();
        }

        if (r > l)
        {
            s.push_back(')');
            backtrace(l, r - 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        backtrace(n, n);
        return res;
    }
};