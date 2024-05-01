#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        return build(s) == build(t);
    }

    string build(string &s)
    {
        string res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '#')
            {
                if (!res.empty())
                    res.pop_back();
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};