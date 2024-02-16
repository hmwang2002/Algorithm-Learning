#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string a = "";
        vector<string> strs;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (a != "")
                {
                    strs.push_back(a);
                    a = "";
                }
            }
            else
            {
                a += s[i];
            }
        }
        if (a != "")
        {
            strs.push_back(a);
        }
        string ans = strs[strs.size() - 1];
        for (int i = strs.size() - 2; i >= 0; i--)
        {
            ans += (" " + strs[i]);
        }
        return ans;
    }
};