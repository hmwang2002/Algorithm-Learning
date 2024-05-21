#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int l = 0, res = 0;
        for (int i = 0; i < n; i++)
        {
            mp[fruits[i]]++;
            while (mp.size() > 2)
            {
                auto it = mp.find(fruits[l]);
                --it->second;
                if (it->second == 0)
                    mp.erase(it);
                l++;
            }
            res = max(res, i - l + 1);
        }
        return res;
    }
};