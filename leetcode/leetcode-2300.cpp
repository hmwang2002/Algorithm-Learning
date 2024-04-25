#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int &x : spells)
        {
            int l = 0, r = (int)potions.size() - 1;
            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if ((long long)x * potions[mid] < success)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
            res.push_back(potions.size() - l);
        }
        return res;
    }
};