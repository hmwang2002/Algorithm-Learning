#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;

public:
    bool isIsomorphic(string s, string t)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
            {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};