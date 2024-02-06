#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string &s : strs)
        {
            string k = s;
            sort(k.begin(), k.end());
            mp[k].emplace_back(s);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
