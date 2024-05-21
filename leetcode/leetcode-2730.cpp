#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int cnt = 0, l = 0;
        int res = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                cnt++;
            if (cnt > 1)
            {
                l++;
                while (cnt > 1)
                {
                    if (s[l] == s[l - 1])
                        cnt--;
                    else
                        l++;
                }
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};