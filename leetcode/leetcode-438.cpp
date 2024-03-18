#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int s1 = s.size(), s2 = p.size();
        if (s1 < s2)
        {
            return {};
        }

        vector<int> ans;
        vector<int> sCnt(26);
        vector<int> pCnt(26);
        for (int i = 0; i < s2; i++)
        {
            sCnt[s[i] - 'a']++;
            pCnt[p[i] - 'a']++;
        }
        if (sCnt == pCnt)
        {
            ans.push_back(0);
        }

        for (int i = 0; i < s1 - s2; i++)
        {
            --sCnt[s[i] - 'a'];
            ++sCnt[s[i + s2] - 'a'];
            if (sCnt == pCnt)
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};