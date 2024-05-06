#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        int n = word.size();
        int cnt = n / k;
        unordered_map<string, int> mp;
        string s;
        for (int i = 0; i < n; i++)
        {
            if (i % k == 0)
            {
                mp[s]++;
                s = "";
            }
            s += word[i];
        }
        mp[s]++;
        int maxVal = 0;
        for (auto &it : mp)
        {
            maxVal = max(maxVal, it.second);
        }
        return cnt - maxVal;
    }
};