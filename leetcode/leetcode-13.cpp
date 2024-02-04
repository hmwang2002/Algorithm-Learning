#include <bits/stdc++.h>

using namespace std;

class Solution
{
    unordered_map<char, int> umap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

public:
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int value = umap[s[i]];
            if (i < s.size() - 1 && value <= umap[s[i + 1]])
            {
                ans -= value;
            }
            else
            {
                ans += value;
            }
        }
        return ans;
    }
};
