#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp[i] = i + 1;
        }
        for (int i = 0; i < chars.length(); i++)
        {
            mp[chars[i] - 'a'] = vals[i];
        }
        int ans = 0;
        int f = 0;
        for (int i = 0; i < s.length(); i++)
        {
            f = max(0, f) + mp[s[i] - 'a'];
            ans = max(ans, f);
        }
        return ans;
    }
};